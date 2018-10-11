//Student2.c by Daniel McDonough 9/28/18

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project2.h"



//increment sequence number by 1
void get_next_seq_num(struct sender_window* window) {
	window->next_seq_num ++;
}

//update reciever seqnum
void update_recv_seq_num(struct receiver_window* window) {
	window->expected_seq_num ++;
}

//helper functions for the checksum
#define BUF_SIZE 37 // 16 bits + 20 rows + 1 extra (not used)

//print int to binary for Fletcher's_checksum
char *int2bin(int a, char *buffer, int buf_size) {
    buffer += (buf_size - 1);
	int i;
    for (i = 31; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';
        a >>= 1;
    }
    return buffer;
}

//Originally tried to implement Fletcher's_checksum but then implemented the
//professors checksum which works just as well and is less complicated
//make the checksum
int make_checksum(struct pkt* packet) {
	int checksum = 0;
	checksum += packet->seqnum;
	checksum += packet->acknum;
  //take the sum of the payload
	int i;
	for (i=0;i<20;i++) {
		checksum += ((int) packet->payload[i] * i); // multiply row by index and take the sum
	}

  printf("Setting Checksum = %d\n", ~checksum);
	return ~checksum; //take the 1's compliment
}

//double check the checksum
//returns 0 if good checksum 1 if bad
int check_checksum(struct pkt* packet) {
	int res = 0;
	int checksum = make_checksum(packet);
	printf("Getting Checksum = %d\n",packet->checksum);
	if(checksum == packet->checksum){
		return 1;
	}else{
		return 0;
	}
}

//set the packet as ACK
struct pkt* set_ACK(int seq_num) {
	struct pkt* packet = (struct pkt*) malloc(sizeof(struct pkt));
	memset(packet, 0, sizeof(struct pkt)); //zero out the struct
	packet->seqnum = seq_num;
	packet->acknum = 1;
	packet->checksum = make_checksum(packet);
	return packet;
}



//return all values in a given QUEUE
void** list_get_all(struct list* list) {
	if (list->curr_size == 0) {
		return NULL; // no elements exist in the list
	}
	void** values = (void**) malloc ( sizeof(void*) * list->curr_size);
	void** values_tmp = values;
	void** tmp_head = list->head;//temporary head
		int i;
	for (i=0;i<list->curr_size;i++) {
		*(values_tmp) = *(tmp_head);
		values_tmp++;
		tmp_head++;
		if (tmp_head>= (list->values + list->max_size)) {
			//wrap the head around
			tmp_head = list->values;
		}
	}
	return values;
}

//check if list is full
int is_Queue_full(struct list* list) {
	return list->curr_size == list->max_size;
}

//get list size
int Queue_size(struct list* list) {
	return list->curr_size;
}

//get the first element in the queue
void* get_head_element(struct list* list) {
	return *(list->head);
}

//remove head element in the queue
void* dequeue(struct list* list) {
	void* val = NULL;
	if (list->curr_size > 0) {	//if the list is not empty
		val = *(list->head);
		list->head++;

		if (list->head >= (list->values + list->max_size)) {
			//wrap the head around
			list->head = list->values;
		}
		list->curr_size--; //decrease the current size
	}
	return val;
}
//add to queue
int enqueue(struct list* list, void* value) {
	if (!is_Queue_full(list)) {
		*(list->tail) = value;
		list->tail++; // increase the tail
		list->curr_size++;
		if (list->tail >= (list->values + list->max_size)) {
			//wrap the list around
			list->tail = list->values;
		}
	}
}
//send down to layer 3
void send_message(struct msg* message) {

	struct pkt* packet = (struct pkt*) malloc (sizeof(struct pkt));
	packet->seqnum = A_Window.next_seq_num; // the next seq num
	get_next_seq_num(&A_Window);
	packet->acknum = 0; //no ack status
	memcpy(packet->payload, message->data, 20); //copy data
	// generate a checksum.
	packet->checksum = make_checksum(packet);

	enqueue(A_Window.unacked_packets, packet); //add the packet to unacked list
	//lets actualy send the packet
	tolayer3(AEntity, *packet);

	//only start the timer if there are no other unacked packets
	if (Queue_size(A_Window.unacked_packets) == 1) {
		startTimer(AEntity, timeout);
	}
}

//send up to layer 5
void to_application_layer(struct pkt* packet) {
	struct msg message; // the message to send up
	strncpy(message.data, packet->payload, 20);
	tolayer5(BEntity,message); // send the message up
}


//create a list given the number of total messages
struct list* create_list(int size) {
	struct list* list = (struct list*) malloc (sizeof(struct list));
	list->values = (void**) malloc( sizeof(void*) * size);
	list->max_size = size;
	list->curr_size = 0;
	list->head = list->values;
	list->tail = list->values;
	return list;
}

//Fly like an Eagle...
void free_list(struct list* list) {
	free(list->head);
	free(list);
}
