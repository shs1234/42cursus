** generated for login "hoseoson" **
******* Goal ID 1 ********
forward way : H1 -> H2 (161.127.62.3)
on H1 : packet accepted
on H1: send to H11
on switch S1: pass to all connections
on R1 : packet not for me
on H1 : loop detected
on H2 : packet accepted
on H2: destination IP reached
reverse way : H2 -> H1 (161.127.62.2)
on H2 : packet accepted
on H2: send to H21
on switch S1: pass to all connections
on R1 : packet not for me
on H1 : packet accepted
on H1: destination IP reached
on H2 : loop detected
******* Goal ID 2 ********
forward way : H3 -> H4 (161.127.62.131)
on H3 : packet accepted
on H3: destination does not match any interface. pass through routing table
on H3 : route match 0.0.0.0/0
on H3: send to gateway 161.127.62.200 through interface H31
on R2: invalid IP on input interface R22
******* Goal ID 3 ********
forward way : H1 -> I (163.172.250.1)
on H1 : packet accepted
on H1: destination does not match any interface. pass through routing table
on H1 : route match 0.0.0.0/0
on H1: send to gateway 161.127.62.1 through interface H11
on switch S1: pass to all connections
on R1 : packet accepted
on R1: send to R12
on I : packet accepted
on I: destination IP reached
on H1 : loop detected
on H2 : packet not for me
reverse way : I -> H1 (161.127.62.2)
on I : packet accepted
on I: destination does not match any interface. pass through routing table
on I : route match 161.127.62.0/24
on I: send to gateway 163.172.250.12 through interface I1
on R1 : packet accepted
on R1: send to R11
on switch S1: pass to all connections
on R1 : loop detected
on H1 : packet accepted
on H1: destination IP reached
on H2 : packet not for me
******* Goal ID 4 ********
forward way : H1 -> H4 (161.127.62.131)
on H1 : packet accepted
on H1: destination does not match any interface. pass through routing table
on H1 : route match 0.0.0.0/0
on H1: send to gateway 161.127.62.1 through interface H11
on switch S1: pass to all connections
on R1 : packet accepted
on R1: destination does not match any interface. pass through routing table
on R1 : route match 0.0.0.0/0
on R1: send to gateway 161.127.62.253 through interface R13
on R2 : packet accepted
on interface R22: invalid IP address
on R2: send to R23
on H4 : packet accepted
on H4: destination IP reached
on H1 : loop detected
on H2 : packet not for me
reverse way : H4 -> H1 (161.127.62.2)
on H4 : packet accepted
on H4: destination does not match any interface. pass through routing table
on H4 : route match default
on H4: send to gateway 161.127.62.129 through interface H41
on R2 : packet not for me
******* Goal ID 5 ********
forward way : H2 -> H3 (161.127.62.201)
on H2 : packet accepted
on H2: destination does not match any interface. pass through routing table
on H2 : route match default
on H2: send to gateway 161.127.62.1 through interface H21
on switch S1: pass to all connections
on R1 : packet accepted
on R1: destination does not match any interface. pass through routing table
on R1 : route match 0.0.0.0/0
on R1: send to gateway 161.127.62.253 through interface R13
on R2 : packet accepted
on interface R22: invalid IP address
on R2: destination does not match any interface. pass through routing table
on R2 : route match 0.0.0.0/0
on R2: send to gateway 161.127.62.254 through interface R21
on R1 : loop detected
on interface R22: invalid IP address
on H1 : packet not for me
on H2 : loop detected
******* Goal ID 6 ********
forward way : H3 -> I (163.172.250.1)
on H3 : packet accepted
on H3: destination does not match any interface. pass through routing table
on H3 : route match 0.0.0.0/0
on H3: send to gateway 161.127.62.200 through interface H31
on R2: invalid IP on input interface R22
******* Goal ID 7 ********
forward way : H4 -> I (163.172.250.1)
on H4 : packet accepted
on H4: destination does not match any interface. pass through routing table
on H4 : route match default
on H4: send to gateway 161.127.62.129 through interface H41
on R2 : packet not for me