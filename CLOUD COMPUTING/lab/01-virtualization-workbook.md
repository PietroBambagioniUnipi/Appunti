# LAB – Full Virtualization with KVM/libvirt
## Student Workbook

> Use this workbook alongside the lab slides. Follow the steps in order on your assigned VM.

---

## Infrastructure

Each student is assigned one VM with the following specs:

- **OS:** Ubuntu 22.04 LTS
- **vCPU:** 1 · **RAM:** 7 GB · **Disk:** 40 GB (`/dev/sda`)
- **Network:** `10.1.X.X/9` (private, reachable via VPN)
- **Credentials:** `root` / `ubuntu`

Connect via SSH:
```bash
ssh root@<YOUR_VM_IP>
```

> If you have issues with the VPN, downgrade OpenVPN to version 2.4.

---

## 1 – Check Virtualization Support

Install the checker tool and verify KVM support:

```bash
sudo apt update
sudo apt install cpu-checker
kvm-ok
```

> The VMs provided for this lab do **not** have hardware acceleration — the VMs you create inside will run slower than on a bare-metal host. This is expected.

---

## 2 – Install KVM and libvirt

Install KVM, libvirt, and the supporting tools:

```bash
sudo apt-get install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virtinst
```

> This will take a few minutes.
>
> - **KVM** is the Linux kernel virtualization module — it acts as the hypervisor.
> - **libvirt** is the management layer used to create and configure VMs.
> - **virtinst** provides the `virt-install` command-line tool.

---

## 3 – Configure User Permissions

Add your user to the `libvirt` group:

```bash
sudo adduser `id -un` libvirt
```

Then apply the group change to the current session:

```bash
exec newgrp libvirt
```

---

## 4 – Verify Installation

Check that libvirt is running and list active VMs (none yet):

```bash
virsh list
```

Retrieve hardware information about the host:

```bash
virsh nodeinfo
```

---

## 5 – Install a VM from the Network (Reference Only)

> **Do not run this command.** It is shown here for reference.

A VM can be installed from scratch by pointing `virt-install` to a network installation source:

```bash
sudo virt-install \
  --name Ubuntu \
  --description 'Test VM with Ubuntu' \
  --ram=512 \
  --vcpus=1 \
  --os-type=Linux \
  --os-variant=ubuntu18.04 \
  --disk path=/var/lib/libvirt/images/ubuntu1804.qcow2,bus=virtio,size=1 \
  --graphics none \
  --location 'http://us.archive.ubuntu.com/ubuntu/dists/bionic/main/installer-amd64/' \
  --network bridge:virbr0 \
  --console pty,target_type=serial -x 'console=ttyS0,115200n8 serial'
```

Once a VM is no longer needed it can be force-stopped and its configuration removed:

```bash
virsh destroy Ubuntu
virsh undefine Ubuntu
```

---

## 6 – Import a Pre-installed VM (CirrOS)

Download the CirrOS disk image and move it to the libvirt images directory:

```bash
wget http://download.cirros-cloud.net/0.4.0/cirros-0.4.0-x86_64-disk.img
mv cirros-0.4.0-x86_64-disk.img /var/lib/libvirt/images
```

Import the VM using the existing disk image:

```bash
sudo virt-install \
  --name Cirros \
  --description 'Cirros' \
  --ram=512 \
  --vcpus=1 \
  --os-type=Linux \
  --os-variant=ubuntu18.04 \
  --disk path=/var/lib/libvirt/images/cirros-0.4.0-x86_64-disk.img,bus=virtio,format=raw \
  --network bridge:virbr0 \
  --graphic none \
  --import
```

> The `--import` flag skips installation and boots directly from the disk image. Boot may take a while and show some errors — this is expected as the image was built for a different platform (OpenStack).

If the console is not shown or you disconnected, reconnect with:

```bash
virsh console Cirros
```

> Press `Ctrl+]` to exit the console and return to the host.

---

## 7 – Manage the VM Lifecycle

All commands below are run from the **host**.

Gracefully shut down the VM:
```bash
virsh shutdown Cirros
```

Start it again:
```bash
virsh start Cirros
```

Suspend (freeze in memory):
```bash
virsh suspend Cirros
```

Resume:
```bash
virsh resume Cirros
```

Enable autostart at host boot:
```bash
virsh autostart Cirros
```

Disable autostart:
```bash
virsh autostart --disable Cirros
```

Check VM state at any point:
```bash
virsh list --all
```

---

## 8 – Explore VM Networking

From the **host**, inspect the bridge and virtual network configuration:

```bash
brctl show
virsh net-list
virsh net-dumpxml default
```

Connect to the CirrOS console and inspect networking from inside the VM:

```bash
virsh console Cirros
```

Inside the VM:
```bash
ip addr
ip route
traceroute 8.8.8.8
```

> The first hop in the traceroute should be `192.168.122.1` — the address of `virbr0` on the host, which performs NAT to give the VM internet access.

---

## 9 – Create a New Virtual Network

Create the network definition file:

```bash
cat > net2.xml << 'EOF'
<network>
  <name>net2</name>
  <bridge name="virbr1"/>
  <forward mode="nat"/>
  <ip address="192.168.2.1" netmask="255.255.255.0">
    <dhcp>
      <range start="192.168.2.2" end="192.168.2.254"/>
    </dhcp>
  </ip>
</network>
EOF
```

Define, enable autostart, and start the network:

```bash
virsh net-define net2.xml
virsh net-autostart net2
virsh net-start net2
```

Verify both networks are active:

```bash
virsh net-list
```

Attach a second NIC to the running CirrOS VM on the new network:

```bash
virsh attach-interface --domain Cirros --type network --source net2 --config --live
```

Connect to the CirrOS console and configure the new interface:

```bash
virsh console Cirros
```

Inside the VM:
```bash
sudo ip addr add 192.168.2.10/24 dev eth1
sudo ip link set up dev eth1
ip addr show eth1
```

---

## 10 – Storage Pools and Volumes

List available storage pools and inspect the default one:

```bash
virsh pool-list
virsh pool-info images
virsh pool-dumpxml images
```

Create a new 100 MB volume in the `images` pool:

```bash
virsh vol-create-as images disk2 100M
virsh vol-list images
```

Attach the new volume to the running CirrOS VM as a second disk:

```bash
virsh attach-disk Cirros /var/lib/libvirt/images/disk2 vdb --live
```

Connect to the CirrOS console and set up the disk:

```bash
virsh console Cirros
```

Inside the VM, create a partition:
```bash
sudo fdisk /dev/vdb
```
> In `fdisk`: press `n` → `p` → `1` → Enter (accept defaults) → `w` to write and exit.

Format and mount the partition:
```bash
sudo mkfs.ext4 /dev/vdb1
sudo mount /dev/vdb1 /mnt/
df -h /mnt/
```

---

## 11 – Snapshots

A snapshot captures the full state of a VM (disk and optionally memory) at a point in time, allowing you to roll back if something goes wrong. This is widely used in cloud environments for backups and safe experimentation.

Make sure the CirrOS VM is running, then take a snapshot:

```bash
virsh snapshot-create-as Cirros snap1 "clean state before changes"
```

List the snapshots of the VM:

```bash
virsh snapshot-list Cirros
```

Connect to the CirrOS console and make a visible change inside the VM — for example, create a file:

```bash
virsh console Cirros
```

Inside the VM:
```bash
echo "this will be undone" > /tmp/testfile
cat /tmp/testfile
```

Press `Ctrl+]` to return to the host, then revert to the snapshot:

```bash
virsh snapshot-revert Cirros snap1
```

Reconnect to the console and verify the file is gone:

```bash
virsh console Cirros
```

Inside the VM:
```bash
cat /tmp/testfile
```

Back on the host, delete the snapshot when done:

```bash
virsh snapshot-delete Cirros snap1
virsh snapshot-list Cirros
```

---

## 12 – Clean Up

Destroy and undefine the VM:

```bash
virsh destroy Cirros
virsh undefine Cirros
```

Remove the custom network:

```bash
virsh net-destroy net2
virsh net-undefine net2
```

Uninstall all packages:

```bash
sudo apt-get purge qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virtinst
```

Reboot:

```bash
reboot
```

---

## Bonus – External Bridged Network (Reference Only)

> ⚠️ **Do NOT run these commands on your assigned VM.** A machine with a single NIC will lose network connectivity immediately. This is for servers with at least two network interfaces.

Create a bridge from a physical interface:

```bash
virsh iface-bridge --interface eth1 --bridge ext-br
```

Define an external network (`external.xml`):

```xml
<network>
  <name>external</name>
  <forward mode="bridge" />
  <bridge name="ext-br" />
</network>
```

---

## virsh Quick Reference

| Command | Description |
|---|---|
| `virsh list [--all]` | List VMs |
| `virsh start <name>` | Start a VM |
| `virsh shutdown <name>` | Graceful stop |
| `virsh destroy <name>` | Force stop |
| `virsh suspend / resume <name>` | Pause / unpause |
| `virsh undefine <name>` | Remove VM config |
| `virsh autostart [--disable] <name>` | Toggle autostart |
| `virsh console <name>` | Connect to serial console |
| `virsh nodeinfo` | Host hardware info |
| `virsh net-list [--all]` | List virtual networks |
| `virsh net-define <file>` | Define network from XML |
| `virsh net-start / net-destroy <name>` | Start / stop network |
| `virsh net-autostart <name>` | Enable network autostart |
| `virsh net-dumpxml <name>` | Show network XML config |
| `virsh attach-interface ...` | Add a NIC to a VM |
| `virsh pool-list` | List storage pools |
| `virsh pool-info / pool-dumpxml <name>` | Pool details / config |
| `virsh vol-create-as <pool> <vol> <size>` | Create a volume |
| `virsh vol-list <pool>` | List volumes in a pool |
| `virsh attach-disk ...` | Attach a disk to a VM |
| `virsh snapshot-create-as <vm> <name> <desc>` | Create a snapshot |
| `virsh snapshot-list <vm>` | List snapshots |
| `virsh snapshot-revert <vm> <name>` | Revert to a snapshot |
| `virsh snapshot-delete <vm> <name>` | Delete a snapshot |
