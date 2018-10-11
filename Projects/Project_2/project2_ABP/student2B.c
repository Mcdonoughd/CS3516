//Student2.c by Daniel McDonough 9/28/18

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project2.h"

//Reciever B
struct receiver_window b_window;

/*
 * B_input(packet),where packet is a structure of type pkt. This routine
 * will be called whenever a packet sent from the A-side (i.e., as a result
 * of a tolayer3() being done by a A-side procedure) arrives at the B-side.
 * packet is the (possibly corrupted) packet sent from the A-side.
 */
void B_input(struct pkt packet){
	printf("B recieved a packet! \n");
	//check if checksums match
	if (check_checksum(&packet)) {

		printf("Received packet %d expecting %d \n", packet.seqnum, b_window.expected_seq_num);
		if (b_window.expected_seq_num == packet.seqnum) {

			//if there was a last ACK set it back to NULL
			if (b_window.last_ack != NULL) {
				free(b_window.last_ack);
			}

			struct pkt* ack_pkt = set_ACK(packet.seqnum);
			b_window.last_ack = ack_pkt;

			tolayer3(BEntity, *ack_pkt);//send ack

			update_recv_seq_num(&b_window); //update seqnum

			printf("We are sending the packet up \n");
			to_application_layer(&packet); //send to layer 5
		}
		else {
			printf("Resening ACK! \n");
			tolayer3(BEntity, *(b_window.last_ack)); //resent to b
		}

	}
	else {
		printf("Detected Corruption... \n");
		//lets resend last ack anyways.
		if (b_window.last_ack != NULL) {
			printf("Resending last ACK \n");
			tolayer3(BEntity, *(b_window.last_ack));
		}
	}
}

/*
 * The following routine will be called once (only) before any other
 * entity B routines are called. You can use it to do any initialization
 */
void B_init(){
	b_window.expected_seq_num = 0; //forst seq is always 0
	b_window.last_ack = NULL; //there hast been an ACK yet
}

/*
 * B_timerinterrupt()  This routine will be called when B's timer expires
 * (thus generating a timer interrupt). You'll probably want to use this
 * routine to control the retransmission of packets. See starttimer()
 * and stoptimer() in the writeup for how the timer is started and stopped.
 */
void B_timerinterrupt(){ //used on bidirectional, does not have to be implemented
}

/*
 * Just like A_output, but residing on the B side.  USED only when the
 * implementation is bi-directional.
 */
void B_output(struct msg message){} //ignore for this project
