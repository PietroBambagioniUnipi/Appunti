

Per comprendere l'importanza del supporto hardware nella virtualizzazione, dobbiamo prima ricordare i limiti della **full virtualization classica (senza supporto hardware)**. In quel modello, il Guest OS gira in _user mode_ e non può eseguire direttamente istruzioni privilegiate. Ogni operazione critica (come l'I/O o la gestione degli interrupt) richiede una procedura pesante: _trap → context switch → emulazione_, generando spesso catene di context switch e un elevato **overhead**. Se in passato questo compromesso era accettabile, con l'aumento delle esigenze prestazionali è diventato un limite.

A partire dal 2006, aziende come Intel e AMD hanno introdotto un **supporto hardware specifico** (come **Intel VMX** - _Virtual Machine eXtension_) per ridurre drasticamente questo overhead, permettendo alla VM di eseguire direttamente molte istruzioni privilegiate.

---

## 1. Root e Non-Root Mode

Con Intel VMX, vengono introdotti due nuovi livelli operativi della CPU, completamente indipendenti dai classici _User Mode_ (Ring 3) e _Kernel/System Mode_ (Ring 0). Si creano così 4 combinazioni possibili:

- **Root Mode:** È il livello in cui opera l'**hypervisor** (o l'Host OS). Qui l'esecuzione avviene direttamente sull'hardware con privilegi completi.
    
- **Non-Root Mode:** È il livello dedicato al **codice della VM**. Offre un controllo molto fine su ciò che il Guest OS può o non può eseguire.
    

Sono state inoltre introdotte **nuove istruzioni hardware** per gestire il ciclo di vita delle macchine virtuali:

- `VMLAUNCH` / `VMRESUME`: per avviare o riprendere una VM.
    
- **VM Exit:** il passaggio dalla VM all'hypervisor (quando serve il suo intervento).
    
- **VM Entry:** il ritorno del controllo dall'hypervisor alla VM.
    

**Il grande vantaggio?** Meno emulazione e meno context switch, poiché alcune istruzioni privilegiate possono finalmente essere eseguite in modo nativo dalla VM.

---

## 2. Gestione degli Interrupt Assistita via Hardware

L'obiettivo principale qui è delegare la gestione di alcuni interrupt direttamente alla VM, evitando i noiosi passaggi per l'hypervisor.

Per farlo, viene introdotta la **IRT (Interrupt Remapping Table)**. Questa struttura hardware si posiziona tra la CPU e le tabelle degli interrupt (IDT). Ha una voce per ogni possibile richiesta di interrupt e funge da "smistatore": indirizza gli interrupt o al vettore del VMM o direttamente a quello di una specifica VM. Prima di questo meccanismo, istruzioni come `INT` e `IRET` richiedevano un'emulazione completa; ora, grazie al livello _non-root_ e alla IRT, la loro esecuzione può essere gestita direttamente dal Guest OS.

---

## 3. VMCS (Virtual Machine Control Structure)

Per ogni VM esiste una specifica struttura dati hardware chiamata **VMCS**. Contiene tutte le informazioni vitali della VM (stato della CPU, configurazioni, regole di controllo) e può essere manipolata tramite un set di istruzioni hardware dedicate.

La VMCS è divisa in **6 aree principali**:

1. **Guest State:** Lo stato della VCPU (registri, contesto). Viene caricato durante un _VM Entry_ e salvato durante un _VM Exit_.
    
2. **Host State:** Lo stato della CPU dell'hypervisor. Viene salvato quando si entra nella VM e ripristinato quando se ne esce.
    
3. **VM Execution Control:** Definisce le regole su quali istruzioni possono essere eseguite in _non-root mode_. Se la VM tenta un'istruzione non permessa, scatta un _VM Exit_. Gestisce anche i flag per l'I/O e il passthrough.
    
4. **VM Entry Control:** Regola cosa deve essere caricato o inizializzato durante il passaggio root → non-root.
    
5. **VM Exit Control:** Regola cosa deve essere salvato o aggiornato durante il passaggio inverso (non-root → root).
    
6. **VM Exit Reason:** Memorizza la causa scatenante dell'ultimo _VM Exit_, fondamentale per far capire all'hypervisor come intervenire.
    

> **Nota bene:** Non esiste un passaggio diretto da una VM a un'altra VM. Il flusso è sempre: **VM 1 → Hypervisor → VM 2**.

---

## 4. Gestione della RAM (EPT)

Ogni VM è convinta di avere una memoria tutta per sé, continua e che parte dall'indirizzo 0. Per ottimizzare la traduzione degli indirizzi, l'hardware introduce le **Extended Page Tables (EPT)**. Questa estensione della MMU (Memory Management Unit) gestisce direttamente via hardware la doppia traduzione:

- G: Virtual Guest → Physical Guest
    
- H: Physical Guest → Physical Host
    

La traduzione totale (G∘H) avviene in hardware, eliminando i costosi _VM Exit_ per l'aggiornamento delle page table. Questo comporta più accessi in memoria, ma il ritardo viene efficacemente mitigato dalle memorie cache.

---

## 5. Hardware Passthrough (Dispositivi I/O)

Poiché le operazioni di I/O rappresentano il principale collo di bottiglia, si ricorre al **Passthrough**: si assegna un dispositivo fisico (es. una scheda di rete) _direttamente_ ed _esclusivamente_ a una singola VM.

**Pro e Contro:**

- _Pro:_ Prestazioni elevatissime (quasi native).
    
- _Contro:_ Il dispositivo non può essere condiviso con altre VM, si perde la flessibilità della virtualizzazione su quel device e serve supporto hardware specifico.
    

Per far funzionare il passthrough servono due meccanismi:

1. **Direct Mapping (Memoria):** Lo spazio di memoria I/O del dispositivo fisico viene mappato direttamente nello spazio della VM.
    
2. **Direct Interrupt Assignment:** Gli interrupt del dispositivo arrivano direttamente alla VM (il VMM continua a gestire tutti gli altri).
    

**La I/O Bitmap:** Nella VMCS esiste una _I/O Bitmap_ (1 bit per ogni indirizzo I/O):

- `Bit = 1`: Accesso diretto al dispositivo (Passthrough attivo, nessun VM Exit).
    
- `Bit = 0`: Accesso intercettato (Genera un VM Exit e ci pensa il VMM).
    

---

## 6. Interrupt e Stati della Macchina Virtuale

Con il passthrough, l'hardware usa la tabella degli interrupt del Guest OS (IVT) per eseguire l'handler. Ma sorge un problema: **la VM può ricevere interrupt anche quando non è attualmente in esecuzione sulla CPU fisica.**

Una VM può trovarsi in 3 stati:

- **Running:** In esecuzione su una VCPU. L'interrupt viene gestito subito.
    
- **Ready:** Pronta, ma in attesa del suo turno. L'interrupt viene salvato e gestito non appena la VM passa in _Running_.
    
- **Halted:** Inattiva/Spenta. L'interrupt viene salvato e provoca il risveglio della VM (passa a _Ready_).
    

### I Posted Interrupts

Per gestire gli interrupt quando la VM non è _Running_ senza scomodare il VMM, si usano i **Posted Interrupts**. Il sistema utilizza una struttura dati chiamata **PID (Posted Interrupt Descriptor)** che contiene:

- **PIR (Posted Interrupt Requests):** Un buffer dove vengono fisicamente accumulati/memorizzati gli interrupt.
    
- **SN (Suppress Notification):** Un flag. Se è `0`, la CPU viene notificata subito. Se è `1`, gli interrupt vengono solo accumulati nel buffer.
    
- **NV (Notification Vector):** Il vettore usato per notificare la VM.
    

**Come cambia il PID in base allo stato della VM?**

- **Running:** `SN = 0` (notifica immediata). `NV` punta all'IDT della VM.
    
- **Ready:** `SN = 1` (silenzia la notifica, accumula solo nel PIR).
    
- **Halted:** `SN = 0`. `NV` punta a un vettore di risveglio (_Wake-up vector_). Quando la VM torna _Running_, il VMM inietta nella VM tutti gli interrupt accumulati nel PIR.
    

---

## 7. DMA e IOMMU

I dispositivi che usano l'accesso diretto alla memoria (DMA) leggono e scrivono dati direttamente nella RAM. Per farli funzionare in modo sicuro in un ambiente virtualizzato, serve la **IOMMU**. Questa componente hardware traduce gli indirizzi di memoria per le operazioni di I/O, garantendo che un dispositivo assegnato a una VM non possa accedere, per errore o per dolo, alla RAM di un'altra VM (protezione della memoria) e può generare _page fault_ se necessario.

---

## 8. Nested Virtualization e KVM

- **Nested Virtualization:** È la pratica di far girare una VM dentro un'altra VM. Si ha un Hypervisor Host (Livello 1) sull'hardware fisico e un Hypervisor Guest (Livello 2) dentro la VM, che a sua volta crea altre VM. Il limite principale è che spesso il Livello 2 non vede il supporto hardware. Si ottimizza usando **hypervisor cooperativi**, in cui l'HV2 delega le esecuzioni critiche all'HV1 (richiede stesso software e supporto specifico).
    
- **KVM (Kernel-based Virtual Machine):** È l'infrastruttura di virtualizzazione nativa di Linux. Non è un hypervisor "standalone", ma trasforma il kernel Linux stesso in un hypervisor sfruttando attivamente il supporto hardware. Le VM in KVM girano in un ambiente estremamente vicino all'hardware reale, garantendo altissime prestazioni.