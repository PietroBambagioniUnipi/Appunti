127.0.0.1
localhost

n [computer networking](https://en.wikipedia.org/wiki/Computer_networking "Computer networking"), **localhost** is a [hostname](https://en.wikipedia.org/wiki/Hostname "Hostname") that refers to the current computer used to access it. The name _localhost_ is reserved for [loopback](https://en.wikipedia.org/wiki/Loopback "Loopback") purposes.
It is used to access the [network services](https://en.wikipedia.org/wiki/Network_service "Network service") that are running on the host via the loopback network interface. Using the loopback interface bypasses any local [network interface hardware](https://en.wikipedia.org/wiki/Network_interface_controller "Network interface controller").

## Loopback

Main article: [Loopback](https://en.wikipedia.org/wiki/Loopback "Loopback")

The local loopback mechanism may be used to run a network service on a host without requiring a physical network interface, or without making the service accessible from the networks the computer may be connected to. For example, a locally installed [website](https://en.wikipedia.org/wiki/Website "Website") may be accessed from a Web browser by the [URL](https://en.wikipedia.org/wiki/URL "URL") _http://localhost_ to display its home page.

[IPv4](https://en.wikipedia.org/wiki/IPv4 "IPv4") network standards [reserve](https://en.wikipedia.org/wiki/Reserved_IP_addresses "Reserved IP addresses") the entire address block _127.0.0.0/8_ (more than 16 million addresses) for loopback purposes. That means any packet sent to any of those addresses is looped back. The address **_127.0.0.1_** is the standard address for IPv4 loopback traffic; the rest are not supported by all operating systems. However, they can be used to set up multiple server applications on the host, all listening on the same port number. In the [IPv6 addressing](https://en.wikipedia.org/wiki/IPv6_address "IPv6 address") architecture there is only a single address assigned for loopback: _::1_. The standard precludes the assignment of that address to any physical interface, as well as its use as the source or destination address in any packet sent to remote hosts.

## Name resolution

The name _localhost_ normally resolves to the [IPv4](https://en.wikipedia.org/wiki/IPv4 "IPv4") loopback [address](https://en.wikipedia.org/wiki/IP_address "IP address") _127.0.0.1_, and to the [IPv6](https://en.wikipedia.org/wiki/IPv6 "IPv6") loopback address _::1_.

This resolution is normally configured by the following lines in the operating system's [hosts file](https://en.wikipedia.org/wiki/Hosts_\(file\) "Hosts (file)"):


``` bash
127.0.0.1    localhost
::1          localhost
```


The name may also be resolved by [Domain Name System](https://en.wikipedia.org/wiki/Domain_Name_System "Domain Name System") (DNS) servers, but there are special considerations governing the use of this name:

- An [IPv4](https://en.wikipedia.org/wiki/IPv4 "IPv4") or [IPv6](https://en.wikipedia.org/wiki/IPv6 "IPv6") address query for the name localhost must always resolve to the respective loopback address.
- Applications may resolve the name to a loopback address themselves, or pass it to the local name resolver mechanisms.
- When a name resolver receives an address (A or AAAA) query for _localhost_, it should return the appropriate loopback addresses, and negative responses for any other requested record types. Queries for _localhost_ should not be sent to caching name servers.
- To avoid burdening the [Domain Name System](https://en.wikipedia.org/wiki/Domain_Name_System "Domain Name System") root servers with traffic, caching name servers should never request name server records for _localhost_, or forward resolution to authoritative name servers.
- When authoritative name servers receive queries for 'localhost' in spite of the provisions mentioned above, they should resolve them appropriately.

In addition to the mapping of _localhost_ to the loopback addresses (_127.0.0.1_ and _::1_), _localhost_ may also be mapped to other IPv4 (loopback) addresses and it is also possible to assign other, or additional, names to any loopback address. The mapping of _localhost_ to addresses other than the designated loopback address range in the hosts file or in DNS is not guaranteed to have the desired effect, as applications may map the name internally.

In the Domain Name System, the name _[.localhost](https://en.wikipedia.org/wiki/.localhost ".localhost")_ is reserved as a [top-level](https://en.wikipedia.org/wiki/Top-level_domain "Top-level domain") [domain name](https://en.wikipedia.org/wiki/Domain_name "Domain name"), originally set aside to avoid confusion with the hostname _localhost_. Domain name registrars are precluded from delegating domain names in the top-level _.localhost_ domain.


## Packet processing

The processing of any packet sent to a loopback address, is implemented in the [link layer](https://en.wikipedia.org/wiki/Link_layer "Link layer") of the [TCP/IP stack](https://en.wikipedia.org/wiki/TCP/IP_stack "TCP/IP stack"). Such packets are never passed to any [network interface controller](https://en.wikipedia.org/wiki/Network_interface_controller "Network interface controller") (NIC) or hardware device driver and must not appear outside of a computing system, or be routed by any router. This permits software testing and local services, even in the absence of any hardware network interfaces.

Looped-back packets are distinguished from any other packets traversing the TCP/IP stack only by the special IP address they were addressed to. Thus, the services that ultimately receive them respond according to the specified destination. For example, an HTTP service could route packets addressed to _127.0.0.99:80_ and _127.0.0.100:80_ to different Web servers, or to a single server that returns different web pages. To simplify such testing, the hosts file may be configured to provide appropriate names for each address.

Packets received on a non-loopback interface with a loopback source or destination address must be dropped. Such packets are sometimes referred to as [Martian packets](https://en.wikipedia.org/wiki/Martian_packet "Martian packet"). As with any other bogus packets, they may be malicious and any problems they might cause can be avoided by applying [bogon filtering](https://en.wikipedia.org/wiki/Bogon_filtering "Bogon filtering").

## Special cases

The releases of the [MySQL](https://en.wikipedia.org/wiki/MySQL "MySQL") database differentiate between the use of the hostname _localhost_ and the use of the addresses _127.0.0.1_ and _::1_.When using _localhost_ as the destination in a client connector interface of an application, the MySQL application programming interface connects to the database using a [Unix domain socket](https://en.wikipedia.org/wiki/Unix_domain_socket "Unix domain socket"), while a TCP connection via the loopback interface requires the direct use of the explicit address.

One notable exception to the use of the _127.0.0.0/8_ addresses is their use in Multiprotocol Label Switching (MPLS) traceroute error detection, in which their property of not being routable provides a convenient means to avoid delivery of faulty packets to end users.