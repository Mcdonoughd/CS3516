//Student2.c by Daniel McDonough 9/28/18

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project2.h"



// Sender A
struct sender_window A_Window;

/* Called from Application layer, sends the given message to node B*/
void A_output(struct msg message){

	//check if our window is full
	if (is_Queue_full(A_Window.unacked_packets)) {
		//we have too many packets. buffer the messages
		if (is_Queue_full(A_Window.buffered_messages)) {
			printf("Droping a message, buffer full \n");
		}
		else {
			printf("Window is full, adding to message buffer \n");
			struct msg* message_ptr = (struct msg*) malloc(sizeof(struct msg));
			memcpy(message_ptr, &message, sizeof(struct msg));
			enqueue(A_Window.buffered_messages,message_ptr);
		}

	}

	else {
		//we hae less than 8 outstanding packets
		//send the message
		printf("A window is not full, sending a message \n");
		send_message(&message);
	}
}

/*
 * A_input(packet), where packet is a structure of type pkt. This routine
 * will be called whenever a packet sent from the B-side (i.e., as a result
 * of a tolayer3() being done by a B-side procedure) arrives at the A-side.
 * packet is the (possibly corrupted) packet sent from the B-side.
 */
void A_input(struct pkt packet){
	printf("A has received a pcket. \n");
	//check if the packet is not corrupt
	if (check_checksum(&packet)) {
		//if not corrupt, check if the message was an ACK
		if (packet.acknum == 1 && Queue_size(A_Window.unacked_packets) > 0) {
			printf("A received an ACK \n");

			//the packet is an ack, and there are unacked packets.
			int ack_seq_num = packet.seqnum;

			printf("Getting unACKed packets \n");
				int i;
			for (i=0;i<Queue_size(A_Window.unacked_packets);i++) {
				struct pkt* elt_head = get_head_element(A_Window.unacked_packets); // get_head_element at the first unacked packet
        struct pkt head = *elt_head;
				printf("unACKed packet: %d\n", head.seqnum );
				if (elt_head->seqnum <= ack_seq_num) {
					//if an unACKed packet is less or equal to the ack number dont resend it, remove it from the queue, it was technically ACKed already
					dequeue(A_Window.unacked_packets); //remove it.
					free(elt_head); //fly like an Eagle
				}
				else {
					printf("Seq number is higher, no packets to ack. \n");
					//seq number is not less than packet.
					break;
				}
			}

			if (Queue_size(A_Window.unacked_packets) == 0) {
				//no unacked packets left, stopping timer
				printf("Ack'd all packets, stoping timer \n");
				stopTimer(AEntity);
			}

			printf("Sending any messages in the buffer, that fit in window \n");
			while (!is_Queue_full(A_Window.unacked_packets)&& Queue_size(A_Window.buffered_messages) > 0) {
				//while we have free space in the window, and unbuffered messages
				struct msg* message = dequeue(A_Window.buffered_messages);
				send_message(message); // send a message in the buffered message queue
				//free(message); // free the message now that we are done with it
			}
			//we have acked all unacked packets  before and uncluding the given acl
		}
	}
	else {
		//we received a corrupt packet, just ignore it
		printf("Corrupt packet found!!!\n");
	}
}

/*
 * A_timerinterrupt()  This routine will be called when A's timer expires
 * (thus generating a timer interrupt). You'll probably want to use this
 * routine to control the retransmission of packets. See starttimer()
 * and stoptimer() in the writeup for how the timer is started and stopped.
 */
 void A_timerinterrupt(){
	printf("A Timer Interupt \n");
	//when the timer goes off we resend all unacked packets.
	if (Queue_size(A_Window.unacked_packets) > 0) {
		//resend all unacked packets..
		printf("We have unacked packets, lets resend them \n");

		void** list_elt = list_get_all(A_Window.unacked_packets);
		void** list_head = list_elt;

		int i;
		for (i=0;i<Queue_size(A_Window.unacked_packets);i++) {
			printf("A is sending unacked packet to B \n");
			tolayer3(AEntity, *((struct pkt*) *list_head));
			list_head++;
		}

		free(list_elt); // free the array returned from list_get_all

		startTimer(AEntity, timeout);
	}
	else {
		printf("All packets were already ack'd lets do nothing. \n");
	}
}

/* The following routine will be called once (only) before any other    */
/* entity A routines are called. You can use it to do any initialization */
void A_init(){
  A_Window.next_seq_num = 0; //next seqnum to send
  A_Window.window_size = 1; //window size of the
  A_Window.buffered_messages = create_list(50); //have 50 messages at a time
  A_Window.unacked_packets = create_list(1);
}
