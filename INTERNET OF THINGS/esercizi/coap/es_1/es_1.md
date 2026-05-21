Deploy a CoAP server with only one resource (hello-res)

■ use coap-client to interact with the CoAP Server

– Coap-client is a command line tool (already installed in

the VM) that can be used to test

coap servers

– how to make requests

■ coap-client -m get coap://[address]/[resource]

■ EX: coap-client -m get coap://[fd00::201:1:1:1]/test/hello

■ NOTE: to allow the interaction between the coap-client

(running on the host) and the CoAP Server a border

router is needed

■ Start from the rpl-border-router example and integrate

the code to develop the CoAP Server




_____icnlusi in questa cartella
[[ex2.pdf]]