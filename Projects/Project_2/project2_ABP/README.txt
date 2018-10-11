Reliable	Data	Transfer	Protocol	Simulation
By Daniel McDonough (dmcdonough) 9/27

Note: this program does not account for Out of Order as of 10/4


To run the simulation, first open the command prompt and navigate to the proper directory, where project2.c and
student2.c are located. To begin either run the command: make


----

To run an instance of the client, run the following command:

.\project2 or .\a.out

The program will give the following prompts:

-----  Network Simulator Version    2.3 --------

Enter the number of messages to simulate:
Packet loss probability [enter number between 0.0 and 1.0]:
Packet corruption probability [0.0 for no corruption]:
Packet out-of-order probability [0.0 for no out-of-order]:
Average time between messages from sender's layer5 [ > 0.0]:
Enter Level of tracing desired:
Do you want actions randomized: (1 = yes, 0 = no)?
Do you want Bidirectional: (1 = yes, 0 = no)?

Number of messages to simulate:
The program will stop as soon as this number of messages have been passed
down from layer 5, regardless of whether or not all of the messages have been correctly
delivered. Thus, you need not worry about undelivered or unACK'ed messages still in your
sender when the emulator stops. Note that if you set this value to 1, the program will terminate
immediately, before the message is delivered to the other side. Thus, this value should always be
greater than 1.

Loss:
You are asked to specify a packet loss probability. A value of 0.1 would mean that one in ten
packets (on average) are lost and not delivered to the destination.

Corruption:
You are asked to specify a packet loss probability. A value of 0.2 would mean that two in ten
packets (on average) are corrupted. Note that the contents of payload, sequence, ack, or
checksum fields can be corrupted. Your checksum should thus include the data, sequence, and
ack fields.

Out Of Order:
You are asked to specify an out-of-order probability. A value of 0.2 would mean that two in ten
packets (on average) are reordered.

Tracing:
Setting a tracing value of 1 or 2 will print out useful information about what is going on inside the
emulation (e.g., what's happening to packets and timers). A tracing value of 0 will turn this off. A
tracing value of 5 will display all sorts of odd messages that are for emulator-debugging
purposes. A tracing value of 2 may be helpful to you in debugging your code. You should keep in
mind that real implementers do not have underlying networks that provide such nice information
about what is going to happen to their packets! You will certainly find tracing your own code is
helpful. When the time comes to show off your code, you must have a way of turning off all your
debugging messages. (We will be running with tracing = 1, so you can set your messages to be
displayed only for a higher tracing level – like 3 or 4.
Average time between messages from sender's layer5:
You can set this value to any non-zero, positive value. Note that the smaller the value you choose, the faster packets will be arriving to your sender.

Randomization:
The simulation works by using a random number generator to determine if packets will or will not
be modified in some fashion. Setting 0 here (no randomization) means that you will get the same
result for each of your runs. This can be extremely valuable for debugging. However, for real
testing, you must run with randomization = 1 to see what problems you can shake out. When you
demonstrate your code, I expect to see randomization enabled.

Direction:
The possibilities are Unidirectional = 0, Bidirectional = 1 (Which is not implemented).

Sample Output:

-----  Network Simulator Version    2.3 --------

Enter the number of messages to simulate: 100
Packet loss probability [enter number between 0.0 and 1.0]: 0.1
Packet corruption probability [0.0 for no corruption]: 0.1
Packet out-of-order probability [0.0 for no out-of-order]: 0.1
Average time between messages from sender's layer5 [ > 0.0]: 1
Enter Level of tracing desired: 1
Do you want actions randomized: (1 = yes, 0 = no)? 1
Do you want Bidirectional: (1 = yes, 0 = no)? 0
Input parameters:
Number of Messages = 100  Lost Packet Prob. =   0.100
Corrupt Packet Prob. =   0.100  Out Of Order Prob. =   0.100
Ave. time between messages =     1.00  Trace level = 1
Randomize = 1  Bi-directional = 0

A:       1.9298,  Layer 5 to 4  Message = !fEVhy->Pbs'2J3m~2DU
A window is not full, sending a message
A:       3.6117,  Layer 5 to 4  Message = ##i.Qt9]!Eh-Ps8[~Dg,
Window is full, adding to message buffer
A:       5.2676,  Layer 5 to 4  Message = $X$d:oFzQ(]3h>sJ~U,a
Window is full, adding to message buffer
A:       6.0948,  Layer 5 to 4  Message = %kS%$jR:#iQ9!hP8~gO7
Window is full, adding to message buffer
A:       7.3743,  Layer 5 to 4  Message = &}wq&e_XRLF?93-'~xrl
Window is full, adding to message buffer
A:       7.9858,  Layer 5 to 4  Message = '2=IT'kv$x:FQ]hs~,7C
Window is full, adding to message buffer
A:       9.2216,  Layer 5 to 4  Message = (Eb~=Z(6SpxLi(Eb~=Zw
Window is full, adding to message buffer
A:      10.2538,  Layer 5 to 4  Message = dW(V'U&)%S$R2Q!P~O}N
Window is full, adding to message buffer
A:      10.9863,  Layer 5 to 4  Message = *jL.nP2r*6vX:z]>~aC%
Window is full, adding to message buffer
A:      11.9646,  Layer 5 to 4  Message = +fpdWK>2&+k_RF3-~rfY
Window is full, adding to message buffer
A:      12.8222,  Layer 5 to 4  Message = ,16;AFKPUZ,ejoty~&+0
Window is full, adding to message buffer
A:      13.8898,  Layer 5 to 4  Message = -DZq*AWn'=T-$:Qh~7Ne
Window is full, adding to message buffer
A:      15.7659,  Layer 5 to 4  Message = .V~Iq;d.V~Iq.d.V~Iq;
Window is full, adding to message buffer
A:      16.7524,  Layer 5 to 4  Message = xiE~Z6pL(b=wSxiE~Z6p
Window is full, adding to message buffer
A:      18.2556,  Layer 5 to 4  Message = d{iVD1|jWE2}2X03~lYG
Window is full, adding to message buffer
A:      19.5922,  Layer 5 to 4  Message = 10x.-,+*)('&%$#1~}|{
Window is full, adding to message buffer
A:      20.9543,  Layer 5 to 4  Message = 2CSdt'7HXiy,<M^n21BR
Window is full, adding to message buffer
A:      22.5512,  Layer 5 to 4  Message = 3Uw;^!Df*Ln2Tv:]~3e)
Window is full, adding to message buffer
A:      23.6822,  Layer 5 to 4  Message = 4f=qGzP&Yxc8lB3K~T4^
Window is full, adding to message buffer
A:      24.6522,  Layer 5 to 4  Message = 5zbI0u]D+pW>&kR9~fM5
Window is full, adding to message buffer
A:      24.7360,  Layer 5 to 4  Message = 6x(~wpibZSLE=6x(~wpi
Window is full, adding to message buffer
A:      25.4022,  Layer 5 to 4  Message = d7LVaku!,6AK2`jt~+5?
Window is full, adding to message buffer
A:      26.7426,  Layer 5 to 4  Message = 8T8.Jf$?[w5Qm+Gc~<Xt
Window is full, adding to message buffer
A:      28.2719,  Layer 5 to 4  Message = 9g693a0^-Z*W'T$Q~N{K
Window is full, adding to message buffer
A:      29.9370,  Layer 5 to 4  Message = :yZ;:[<{]=|^>}_?~`A!
Window is full, adding to message buffer
A:      30.7415,  Layer 5 to 4  Message = ;.~qd;I;.~qdVI;.~qdV
Window is full, adding to message buffer
A:      31.5110,  Layer 5 to 4  Message = <AEIMQ<Y^bfjnrvz~%)-
Window is full, adding to message buffer
A:      32.1282,  Layer 5 to 4  Message = =fi~6Lb=xEZp(=3i~6Lb
Window is full, adding to message buffer
A:      33.4434,  Layer 5 to 4  Message = dfxV}Gn7>(Ov2g0W~Ho8
Window is full, adding to message buffer
A:      34.3472,  Layer 5 to 4  Message = ?xS.gBzU0?D|W2kF~Y4m
Window is full, adding to message buffer
A:      35.1450,  Layer 5 to 4  Message = A-wdP<)s`LA%o[H4~kWD
Window is full, adding to message buffer
A:      35.4299,  Layer 5 to 4  Message = B?=;97531x-B)'%#~|zx
Window is full, adding to message buffer
A:      37.3455,  Layer 5 to 4  Message = CRbq#2BQap!1CP`o~0?O
Window is full, adding to message buffer
A:      38.5890,  Layer 5 to 4  Message = De(Ij-No2St7XD<^~Bc&
Window is full, adding to message buffer
A:      40.0506,  Layer 5 to 4  Message = EwL~S(Zxb6i=pEEL~S(Z
Window is full, adding to message buffer
A:      40.2700,  Layer 5 to 4  Message = d,pV<#gM3w^D2nTF~eK1
Window is full, adding to message buffer
A:      40.5839,  Layer 5 to 4  Message = Gf6.&{skcZRJB93)Gvnf
Window is full, adding to message buffer
A:      41.0943,  Layer 5 to 4  Message = HQZdmv!+4=GPYclu~H3<
Window is full, adding to message buffer
A:      41.6905,  Layer 5 to 4  Message = Id~;Vq.Id~;Vq.Id~;Iq
Window is full, adding to message buffer
A:      42.0492,  Layer 5 to 4  Message = JvEq?l:g5b0]+W&R~MyJ
Window is full, adding to message buffer
A:      43.5359,  Layer 5 to 4  Message = K+iI)gG'eE%cC#aA~_>|
Window is full, adding to message buffer
A:      44.8721,  Layer 5 to 4  Message = LLx~pbSE6(wiZL=x~pbS
Window is full, adding to message buffer
A:      46.3031,  Layer 5 to 4  Message = dPMVY]`cfilo2ux{~$'*
Window is full, adding to message buffer
A:      47.8288,  Layer 5 to 4  Message = NcwNCWl#7Lau,AUj~5J_
Window is full, adding to message buffer
A:      48.0449,  Layer 5 to 4  Message = Ou=dORxAgxU{Dj2X~Gm5
Window is full, adding to message buffer
A:      49.4334,  Layer 5 to 4  Message = Pfb;sP'_8pJ$[53G~X2j
Window is full, adding to message buffer
A:      51.3251,  Layer 5 to 4  Message = Q<(q]HQ|hS>*s_J5~jUA
Window is full, adding to message buffer
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
A:      52.8374,  Layer 5 to 4  Message = ROLIFC?R9630-*'$~{xu
Window is full, adding to message buffer
A:      53.9265,  Layer 5 to 4  Message = Sbp~x=LZSw(6ESbp~x=L
Window is full, adding to message buffer
A:      54.1180,  Layer 5 to 4  Message = dt6Vv8Xx:Tz<2|>_~Aa#
Window is full, adding to message buffer
A:      55.9792,  Layer 5 to 4  Message = U)Z.`3e8j=UCtHyM~R&W
Window is full, adding to message buffer
A:      56.8930,  Layer 5 to 4  Message = V;~dI.qV;~dV.qV;~dI.
Droping a message, buffer full
A:      58.5392,  Layer 5 to 4  Message = WNE;2)}tkbXOW<3*~ulc
Droping a message, buffer full
B recieved a message!
Received packet 0 expecting 0
Sending ACK

We are sending the packet up to application layer
B:      58.8406,  Layer 4 to 5  Message = !fEVhy->Pbs'2J3m~2DU
B successfully received 1 packets
A:      58.9483,  Layer 5 to 4  Message = Xaiqy$,4<EMU^Xnv~)19
Droping a message, buffer full
A:      59.3613,  Layer 5 to 4  Message = YfxIc|8Rl(B[u1Ye~:Tn
Droping a message, buffer full
A:      60.7865,  Layer 5 to 4  Message = Z(S~LwEp=i6bxZ(Z~LwE
Droping a message, buffer full
A:      61.6796,  Layer 5 to 4  Message = d:wV5rQ0mL+h2&cB[^<y
Droping a message, buffer full
A:      61.7668,  Layer 5 to 4  Message = ]M=.|m^N>x}n_O?0~]`P
Droping a message, buffer full
A:      63.5219,  Layer 5 to 4  Message = ^`bdfhjlnprtvxz|~#^'
Droping a message, buffer full
A:      65.2610,  Layer 5 to 4  Message = _r(;Ocv,?Sgz0DWk~4H_
Droping a message, buffer full
A:      66.3871,  Layer 5 to 4  Message = `'Lq8^%Jo6[#Hm4Y~Fk2
Droping a message, buffer full
A:      66.5821,  Layer 5 to 4  Message = aapI!X1hAwP)`8oH~W0g
Droping a message, buffer full
A:      67.5095,  Layer 5 to 4  Message = bLb~iS=(pZExwbL6~iS=
Droping a message, buffer full
A:      69.4228,  Layer 5 to 4  Message = dfZcRNJFB=952-3%~zvr
Droping a message, buffer full
A:      71.4176,  Layer 5 to 4  Message = dq~.dIVdq~.;IVdq~.;I
Droping a message, buffer full
A:      71.8163,  Layer 5 to 4  Message = e&Ed%ec$Cb#Ba!A`~?_}
Droping a message, buffer full
A:      72.7259,  Layer 5 to 4  Message = f8i;l>fBrEuHxK{N~Q$T
Droping a message, buffer full
A:      73.8165,  Layer 5 to 4  Message = gKxqU9{gD(jN2tX<~cG+
Droping a message, buffer full
A:      74.8595,  Layer 5 to 4  Message = h^SI>4*}hi_TJ?5+~tj`
Droping a message, buffer full
A:      76.0255,  Layer 5 to 4  Message = ipw~(x6=EiSZbipw~(x6
Droping a message, buffer full
A:      76.8328,  Layer 5 to 4  Message = d%=Vo*C[txja24Mf~9Rk
Droping a message, buffer full
A:      77.9272,  Layer 5 to 4  Message = k7b.X%OyFp<k3^*T~KuB
Droping a message, buffer full
A:      77.9803,  Layer 5 to 4  Message = lf(dB}[9uS1ml)3C~]:v
Droping a message, buffer full
A:      78.0973,  Layer 5 to 4  Message = m]L;+xhWG6&scmB1~n^M
Droping a message, buffer full
A:      78.7825,  Layer 5 to 4  Message = nopqrstuvwxyz{n}~!#$
Droping a message, buffer full
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A:      79.2130,  Layer 5 to 4  Message = o$6I[n#5HZm!4GYo~3FX
Window is full, adding to message buffer
A:      80.0978,  Layer 5 to 4  Message = p6Z~EixSw=b(Lp6ZpEix
Droping a message, buffer full
A:      80.6115,  Layer 5 to 4  Message = dI~V.d;qI~V.2;qI~q.d
Droping a message, buffer full
A:      82.0742,  Layer 5 to 4  Message = r[E.u_H1xbK4{eN7~hr:
Droping a message, buffer full
A:      83.8874,  Layer 5 to 4  Message = snid_YTOJE?:50+&~yts
Droping a message, buffer full
A:      84.3060,  Layer 5 to 4  Message = t#x;HTamy(4AMYfr~-9F
Droping a message, buffer full
A:      85.7152,  Layer 5 to 4  Message = uuSq1Om-Ki)Ge%3a~>]z
Droping a message, buffer full
A:      86.8156,  Layer 5 to 4  Message = vHvIxJyKzL{M|N}O~P!Q
Droping a message, buffer full
A:      88.7103,  Layer 5 to 4  Message = wZ=wbE(iLxpS6wZ=~bE(
Droping a message, buffer full
A:      89.7029,  Layer 5 to 4  Message = dmbVx?4){peY2C7,~sh]
Droping a message, buffer full
A:      90.4655,  Layer 5 to 4  Message = y!(.4yAGMSY`flrx~'-3
Droping a message, buffer full
A:      92.0728,  Layer 5 to 4  Message = z4Ld{5ze|6Nf}7Og~8Ph
Droping a message, buffer full
A:      92.2219,  Layer 5 to 4  Message = {Gp;e0Y{NwCl7a,U~Js>
Droping a message, buffer full
A:      92.5007,  Layer 5 to 4  Message = |Y6qN+fC|Z7rO,gD~[8s
Droping a message, buffer full
A:      93.7635,  Layer 5 to 4  Message = }lZI7&raO},xgUD2~m[J
Droping a message, buffer full
A:      94.1256,  Layer 5 to 4  Message = ~fDUgx,=Oa~&7I3l}1CT
Droping a message, buffer full
A:      95.6791,  Layer 5 to 4  Message = !3EVhy->Pbs'2J[m~2DU
Droping a message, buffer full
B recieved a message!
Received packet 1 expecting 1
Sending ACK

We are sending the packet up to application layer
B:      95.7382,  Layer 4 to 5  Message = ##i.Qt9]!Eh-Ps8[~Dg,
B successfully received 2 packets
A:      95.8499,  Layer 5 to 4  Message = ##i.Qt9]!Eh-Ps8[~Dg,
Droping a message, buffer full
A:      97.6262,  Layer 5 to 4  Message = $X$d:oFzQ(]3h>sJ~U,a
Droping a message, buffer full
A:      98.4416,  Layer 5 to 4  Message = %kS%$jR:#iQ9!hP8~gO7
Droping a message, buffer full
A:      99.8457,  Layer 5 to 4  Message = &}wq&e_XRLF?93-'~xrl
Droping a message, buffer full
A:     101.0318,  Layer 5 to 4  Message = '2=IT'kv$x:FQ]hs~,7C
Droping a message, buffer full
A:     101.0695,  Layer 5 to 4  Message = (Eb~=Z(6SpxLi(Eb~=Zw
Droping a message, buffer full
A:     101.3911,  Layer 5 to 4  Message = dW(V'U&)%S$R2Q!P~O}N
Droping a message, buffer full
A:     102.1498,  Layer 5 to 4  Message = *fL.nP2r*6vX:z3>~aC%
Droping a message, buffer full
A:     103.9667,  Layer 5 to 4  Message = +|pdWK>2&+k_RF9-~rfY
Droping a message, buffer full
A:     104.0137,  Layer 5 to 4  Message = ,16;AFKPUZ,ejoty~&+0
Droping a message, buffer full
A:     105.9480,  Layer 5 to 4  Message = -DZq*AWn'=T-$:Qh~7Ne
Droping a message, buffer full
A:     107.9113,  Layer 5 to 4  Message = .V~Iq;d.V~Iq.d.V~Iq;
Droping a message, buffer full
A:     108.0893,  Layer 5 to 4  Message = xiE~Z6pL(b=wSxiE~Z6p
Droping a message, buffer full
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5120
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 2 expecting 2
Sending ACK

We are sending the packet up to application layer
B:     115.2838,  Layer 4 to 5  Message = $X$d:oFzQ(]3h>sJ~U,a
B successfully received 3 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4830
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 3 expecting 3
Sending ACK

We are sending the packet up to application layer
B:     132.7564,  Layer 4 to 5  Message = %kS%$jR:#iQ9!hP8~gO7
B successfully received 4 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 4 expecting 4
Sending ACK

We are sending the packet up to application layer
B:     222.0190,  Layer 4 to 5  Message = &}wq&e_XRLF?93-'~xrl
B successfully received 5 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5120
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 5 expecting 5
Sending ACK

We are sending the packet up to application layer
B:     244.3300,  Layer 4 to 5  Message = '2=IT'kv$x:FQ]hs~,7C
B successfully received 6 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51e0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 6 expecting 6
Sending ACK

We are sending the packet up to application layer
B:     280.6889,  Layer 4 to 5  Message = (Eb~=Z(6SpxLi(Eb~=Zw
B successfully received 7 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 6 expecting 7
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received a corrupt packet
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 6 expecting 7
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51b0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 7 expecting 7
Sending ACK

We are sending the packet up to application layer
B:     413.7725,  Layer 4 to 5  Message = dW(V'U&)%S$R2Q!P~O}N
B successfully received 8 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51e0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 8 expecting 8
Sending ACK

We are sending the packet up to application layer
B:     443.6322,  Layer 4 to 5  Message = *jL.nP2r*6vX:z]>~aC%
B successfully received 9 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4830
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 9 expecting 9
Sending ACK

We are sending the packet up to application layer
B:     486.7325,  Layer 4 to 5  Message = +fpdWK>2&+k_RF3-~rfY
B successfully received 10 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51b0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 10 expecting 10
Sending ACK

We are sending the packet up to application layer
B:     527.1935,  Layer 4 to 5  Message = ,16;AFKPUZ,ejoty~&+0
B successfully received 11 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51e0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 10 expecting 11
Sending last ACK
B recieved a message!
Received packet 11 expecting 11
Sending ACK

We are sending the packet up to application layer
B:     589.2941,  Layer 4 to 5  Message = -DZq*AWn'=T-$:Qh~7Ne
B successfully received 12 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Seq number is higher, no packets to ack.
Acknowledged 0 packets
Sending any messages in the buffer, that fit in window
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 11 expecting 12
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4830
Seq number is higher, no packets to ack.
Acknowledged 0 packets
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 12 expecting 12
Sending ACK

We are sending the packet up to application layer
B:     635.0571,  Layer 4 to 5  Message = .V~Iq;d.V~Iq.d.V~Iq;
B successfully received 13 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4830
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
B recieved a corrupt packet
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Seq number is higher, no packets to ack.
Acknowledged 0 packets
Sending any messages in the buffer, that fit in window
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 13 expecting 13
Sending ACK

We are sending the packet up to application layer
B:     722.6833,  Layer 4 to 5  Message = xiE~Z6pL(b=wSxiE~Z6p
B successfully received 14 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 14 expecting 14
Sending ACK

We are sending the packet up to application layer
B:     745.3458,  Layer 4 to 5  Message = d{iVD1|jWE2}2X03~lYG
B successfully received 15 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 14 expecting 15
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4a80
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 15 expecting 15
Sending ACK

We are sending the packet up to application layer
B:     802.8578,  Layer 4 to 5  Message = 10x.-,+*)('&%$#1~}|{
B successfully received 16 packets
A has received a pcket, lets check if it is valid and an ACK
A received a corrupt packet
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
B recieved a corrupt packet
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4830
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 16 expecting 16
Sending ACK

We are sending the packet up to application layer
B:     885.5620,  Layer 4 to 5  Message = 2CSdt'7HXiy,<M^n21BR
B successfully received 17 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 17 expecting 17
Sending ACK

We are sending the packet up to application layer
B:     942.1815,  Layer 4 to 5  Message = 3Uw;^!Df*Ln2Tv:]~3e)
B successfully received 18 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5120
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 18 expecting 18
Sending ACK

We are sending the packet up to application layer
B:     961.8866,  Layer 4 to 5  Message = 4f=qGzP&Yxc8lB3K~T4^
B successfully received 19 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
B recieved a corrupt packet
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 19 expecting 19
Sending ACK

We are sending the packet up to application layer
B:    1082.5707,  Layer 4 to 5  Message = 5zbI0u]D+pW>&kR9~fM5
B successfully received 20 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 19 expecting 20
Sending last ACK
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 19 expecting 20
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4830
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 20 expecting 20
Sending ACK

We are sending the packet up to application layer
B:    1254.8170,  Layer 4 to 5  Message = 6x(~wpibZSLE=6x(~wpi
B successfully received 21 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5120
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 21 expecting 21
Sending ACK

We are sending the packet up to application layer
B:    1290.7145,  Layer 4 to 5  Message = d7LVaku!,6AK2`jt~+5?
B successfully received 22 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51b0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 22 expecting 22
Sending ACK

We are sending the packet up to application layer
B:    1305.1469,  Layer 4 to 5  Message = 8T8.Jf$?[w5Qm+Gc~<Xt
B successfully received 23 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4a80
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 23 expecting 23
Sending ACK

We are sending the packet up to application layer
B:    1332.3791,  Layer 4 to 5  Message = 9g693a0^-Z*W'T$Q~N{K
B successfully received 24 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5120
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 24 expecting 24
Sending ACK

We are sending the packet up to application layer
B:    1360.1308,  Layer 4 to 5  Message = :yZ;:[<{]=|^>}_?~`A!
B successfully received 25 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51b0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 25 expecting 25
Sending ACK

We are sending the packet up to application layer
B:    1371.9360,  Layer 4 to 5  Message = ;.~qd;I;.~qdVI;.~qdV
B successfully received 26 packets
A has received a pcket, lets check if it is valid and an ACK
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 25 expecting 26
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4a80
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 26 expecting 26
Sending ACK

We are sending the packet up to application layer
B:    1439.4719,  Layer 4 to 5  Message = <AEIMQ<Y^bfjnrvz~%)-
B successfully received 27 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 27 expecting 27
Sending ACK

We are sending the packet up to application layer
B:    1457.3627,  Layer 4 to 5  Message = =fi~6Lb=xEZp(=3i~6Lb
B successfully received 28 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4830
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 28 expecting 28
Sending ACK

We are sending the packet up to application layer
B:    1499.4651,  Layer 4 to 5  Message = dfxV}Gn7>(Ov2g0W~Ho8
B successfully received 29 packets
A has received a pcket, lets check if it is valid and an ACK
A received a corrupt packet
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 28 expecting 29
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4a80
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 29 expecting 29
Sending ACK

We are sending the packet up to application layer
B:    1574.8441,  Layer 4 to 5  Message = ?xS.gBzU0?D|W2kF~Y4m
B successfully received 30 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 30 expecting 30
Sending ACK

We are sending the packet up to application layer
B:    1592.4466,  Layer 4 to 5  Message = A-wdP<)s`LA%o[H4~kWD
B successfully received 31 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5120
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 31 expecting 31
Sending ACK

We are sending the packet up to application layer
B:    1630.2497,  Layer 4 to 5  Message = B?=;97531x-B)'%#~|zx
B successfully received 32 packets

Printing the contents of the Simulation Event Q
Event Time = 1660.730 A: LAYER 3  Seq/Ack/Check = 31/1/32:

A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B

Printing the contents of the Simulation Event Q
Event Time = 1672.526 B: LAYER 3  Seq/Ack/Check = 31/0/1107297676:  B?=;97531x-)'%#~|zx
Event Time = 1702.092 A: Timer

A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4a80
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window

Printing the contents of the Simulation Event Q
Event Time = 1710.730 A: Timer

B recieved a message!
B recieved a corrupt packet
Sending last ACK

Printing the contents of the Simulation Event Q
Event Time = 1710.730 A: Timer

A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51e0
Seq number is higher, no packets to ack.
Acknowledged 0 packets
Sending any messages in the buffer, that fit in window

Printing the contents of the Simulation Event Q

A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B

Printing the contents of the Simulation Event Q
Event Time = 1760.730 A: Timer

B recieved a message!
B recieved a corrupt packet
Sending last ACK

Printing the contents of the Simulation Event Q
Event Time = 1760.730 A: Timer

A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51e0
Seq number is higher, no packets to ack.
Acknowledged 0 packets
Sending any messages in the buffer, that fit in window

Printing the contents of the Simulation Event Q

A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B

Printing the contents of the Simulation Event Q

A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B

Printing the contents of the Simulation Event Q
Event Time = 1860.730 A: Timer

B recieved a message!
Received packet 32 expecting 32
Sending ACK

We are sending the packet up to application layer
B:    1838.9841,  Layer 4 to 5  Message = CRbq#2BQap!1CP`o~0?O
B successfully received 33 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51e0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 32 expecting 33
Sending last ACK
B recieved a message!
Received packet 33 expecting 33
Sending ACK

We are sending the packet up to application layer
B:    1893.9579,  Layer 4 to 5  Message = De(Ij-No2St7XD<^~Bc&
B successfully received 34 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Seq number is higher, no packets to ack.
Acknowledged 0 packets
Sending any messages in the buffer, that fit in window
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 33 expecting 34
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Seq number is higher, no packets to ack.
Acknowledged 0 packets
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 34 expecting 34
Sending ACK

We are sending the packet up to application layer
B:    1947.4474,  Layer 4 to 5  Message = EwL~S(Zxb6i=pEEL~S(Z
B successfully received 35 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 35 expecting 35
Sending ACK

We are sending the packet up to application layer
B:    1978.6487,  Layer 4 to 5  Message = d,pV<#gM3w^D2nTF~eK1
B successfully received 36 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51b0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 36 expecting 36
Sending ACK

We are sending the packet up to application layer
B:    2001.1893,  Layer 4 to 5  Message = Gf6.&{skcZRJB93)Gvnf
B successfully received 37 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 37 expecting 37
Sending ACK

We are sending the packet up to application layer
B:    2036.0935,  Layer 4 to 5  Message = HQZdmv!+4=GPYclu~H3<
B successfully received 38 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 38 expecting 38
Sending ACK

We are sending the packet up to application layer
B:    2076.2964,  Layer 4 to 5  Message = Id~;Vq.Id~;Vq.Id~;Iq
B successfully received 39 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 38 expecting 39
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51b0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 39 expecting 39
Sending ACK

We are sending the packet up to application layer
B:    2201.4140,  Layer 4 to 5  Message = JvEq?l:g5b~]+W&R0MyJ
		TOLAYER5:  PANIC!!  Data Received in this packet are wrong
B successfully received 40 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 39 expecting 40
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51e0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 40 expecting 40
Sending ACK

We are sending the packet up to application layer
B:    2326.0307,  Layer 4 to 5  Message = K+iI)gG'eE%cC#aA~_>|
B successfully received 41 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5210
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 41 expecting 41
Sending ACK

We are sending the packet up to application layer
B:    2368.8644,  Layer 4 to 5  Message = LLx~pbSE6(wiZL=x~pbS
B successfully received 42 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 41 expecting 42
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51b0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 42 expecting 42
Sending ACK

We are sending the packet up to application layer
B:    2426.3297,  Layer 4 to 5  Message = dPMVY]`cfilo2ux{~$'*
B successfully received 43 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 43 expecting 43
Sending ACK

We are sending the packet up to application layer
B:    2459.5210,  Layer 4 to 5  Message = NcwNCWl#7Lau,AUj~5J_
B successfully received 44 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 44 expecting 44
Sending ACK

We are sending the packet up to application layer
B:    2508.6234,  Layer 4 to 5  Message = Ou=dORxAgxU{Dj2X~Gm5
B successfully received 45 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51b0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 45 expecting 45
Sending ACK

We are sending the packet up to application layer
B:    2531.5527,  Layer 4 to 5  Message = Pfb;sP'_8pJ$[53G~X2j
B successfully received 46 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 46 expecting 46
Sending ACK

We are sending the packet up to application layer
B:    2570.3553,  Layer 4 to 5  Message = Q<(q]HQ|hS>*s_J5~jUA
B successfully received 47 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc50f0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 47 expecting 47
Sending ACK

We are sending the packet up to application layer
B:    2602.7587,  Layer 4 to 5  Message = ROLIFC?R9630-*'$~{xu
B successfully received 48 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc51b0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 48 expecting 48
Sending ACK

We are sending the packet up to application layer
B:    2646.9590,  Layer 4 to 5  Message = Sbp~x=LZSw(6ESbp~x=L
B successfully received 49 packets
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4ab0
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 49 expecting 49
Sending ACK

We are sending the packet up to application layer
B:    2676.5638,  Layer 4 to 5  Message = dt6Vv8Xx:Tz<2|>_~Aa#
B successfully received 50 packets
B recieved a message!
Received packet 48 expecting 50
Sending last ACK
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc4a80
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5120
Seq number is higher, no packets to ack.
Acknowledged 0 packets
Sending any messages in the buffer, that fit in window
B recieved a message!
Received packet 50 expecting 50
Sending ACK

We are sending the packet up to application layer
B:    2707.5442,  Layer 4 to 5  Message = U)Z.`3e8j=UCtHyM~R&W
B successfully received 51 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5120
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window
A Timer Interupt
We have unacked packets, lets resend them
A is sending unacked packet to B
B recieved a message!
Received packet 51 expecting 51
Sending ACK

We are sending the packet up to application layer
B:    2803.5316,  Layer 4 to 5  Message = o$6I[n#5HZm!4GYo~3FX
		TOLAYER5:  PANIC!!  Data Received in this packet are wrong
B successfully received 52 packets
A has received a pcket, lets check if it is valid and an ACK
A received an ACK from B
We are going to go through the list of unacked packets
We found an unacked packet! 1bc5210
Packets seq num is less than ack seq num, removing from window
Acknowledged 1 packets
Ack'd all packets, stoping timer
Sending any messages in the buffer, that fit in window


Simulator terminated at time 2824.869546
 after receiving 52 msgs at layer5
Simulator Analysis:
  Number of messages sent from 5 to 4: 104
  Number of messages received at Layer 5, side A: 0
  Number of messages received at Layer 5, side B: 52
  Number of messages incorrectly received at layer 5: 2
  Number of packets entering the network: 154
  Average number of packets already in network:     0.058
  Number of packets that the network lost: 18
  Number of packets that the network corrupted: 10
  Number of packets that the network put out of order: 17
