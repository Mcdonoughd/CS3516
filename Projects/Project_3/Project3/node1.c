//node1.c by Daniel McDonough 10/6/18
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "project3.h"

extern int TraceLevel;
//These two should have been here when handing out the assignment
extern float clocktime; //clcocktime
extern int ConnectCosts[MAX_NODES][MAX_NODES]; //Connection cost given from the config file

struct distance_table {
  int costs[MAX_NODES][MAX_NODES];
};
struct distance_table dt1; //node's distance table of the whole system
struct NeighborCosts   *neighbor1; //used to print things
struct RoutePacket rpkt_1[MAX_NODES]; //DV sent to its neightbors
/* students to write the following two routines, and maybe some others */

/* students to write the following two routines, and maybe some others */
void printdt1( int MyNodeNumber, struct NeighborCosts *neighbor,struct distance_table *dtptr );

int prev_DV_1[MAX_NODES]; //array that keeps the a cached DV in respect to Node0. INIT =  {1,0,1,INFINITY}

//for each known node get the smallest distance to it and put it in the cached DV
void calc_min_cost1(){
    //calculate the minimum cost to every other node
    int i;
    for(i=0;i<MAX_NODES;i++){
        prev_DV_1[i] = min_distance(dt1.costs[i]);
    }
}

//send packet from node 0
void send_pkt_1(){
  //make the packets
  int i;
   for(i=0;i<MAX_NODES;i++) {
       rpkt_1[i].sourceid = Node1_ID;
       rpkt_1[i].destid = i; //
       memcpy(rpkt_1[i].mincost, prev_DV_1, sizeof(prev_DV_1)); //make a copy of the pacets
   }

   // SEND TO ALL NEIGHBOURS
   
   for(i=0;i<MAX_NODES;i++) {
       if(i!=Node1_ID) {   //not sending to itself
           toLayer2(rpkt_1[i]);
           printf("At time t=%.3f, node %d sends packet to node %d with: (%d  %d  %d  %d)\n",
                  clocktime, rpkt_1[i].sourceid, rpkt_1[i].destid, rpkt_1[i].mincost[0], rpkt_1[i].mincost[1],
                  rpkt_1[i].mincost[2],rpkt_1[i].mincost[3]);
       }
     }
}

//Check if DV has changed. if so send the new one to neighbors
void send_update_pkt1() {
  int old_min_cost[MAX_NODES];
  memcpy(old_min_cost, prev_DV_1, sizeof(prev_DV_1));
  int change = 0;//boolean value to check if any data does not match the cahced DV
  calc_min_cost1();
  int i;
  for(i=0;i<MAX_NODES;i++){
      if(old_min_cost[i]!=prev_DV_1[i]){
          change = 1;
      }
  }
  if(change == 1){    //min cost changed, so send new packets
      send_pkt_1();
  }
  else
      printf("\n Min cost didn't change. \n");
}


//init DV baed on neightbors
void rtinit1() {
    printf("At time %0.3f, rtinit1() was called \n", clocktime);

    // Initialize the distance table with the direct costs
    int i;
    int j;
    for(i=0;i<MAX_NODES;i++){
       for(j=0;j<MAX_NODES;j++){
         if(i==j){
           dt1.costs[i][j] =  ConnectCosts[Node1_ID][j]; //the diagonals are direct neightbors

           //init the DV for iteself
           if(i==Node1_ID){
             prev_DV_1[Node1_ID] = 0;//always 0 in reference to itself!
           }else{
             prev_DV_1[i] = dt1.costs[i][j];//its equivalent to the diagonals initally
           }

         }
        else{
          dt1.costs[i][j] = INFINITY; //everything else is unknown
          }
      }
    }

    neighbor1 = getNeighborCosts(Node1_ID);

    printdt1(Node1_ID,neighbor1,&dt1);

    send_pkt_1();
}

//update on recieving a vector
void rtupdate1( struct RoutePacket *rcvdpkt ) {
      int src = rcvdpkt->sourceid;
      int dest = rcvdpkt->destid;
      int mincost[MAX_NODES];//clone of the recieved packet's min cost
      int j;
      for(j= 0; j<MAX_NODES;j++){
          mincost[j] =  rcvdpkt->mincost[j];
        }

    //  printf("rtupdate1() is called at time t=: %0.3f as node %d sent a pkt with (%d  %d  %d  %d)\n", clocktime, src, mincost[0], mincost[1], mincost[2], mincost[3]);


      //update the distance table
      int i;
      for(i=0;i<MAX_NODES;i++){
          int possibleValue = dt1.costs[src][src] + mincost[i];
          if(possibleValue<INFINITY){
                dt1.costs[i][src] = possibleValue;
          }
          else{
                dt1.costs[i][src] = INFINITY;
          }

      }


      neighbor1 = getNeighborCosts(Node1_ID);

      printdt1(Node1_ID,neighbor1,&dt1);

      send_update_pkt1();
}


/////////////////////////////////////////////////////////////////////
//  printdt
//  This routine is being supplied to you.  It is the same code in
//  each node and is tailored based on the input arguments.
//  Required arguments:
//  MyNodeNumber:  This routine assumes that you know your node
//                 number and supply it when making this call.
//  struct NeighborCosts *neighbor:  A pointer to the structure
//                 that's supplied via a call to getNeighborCosts().
//                 It tells this print routine the configuration
//                 of nodes surrounding the node we're working on.
//  struct distance_table *dtptr: This is the running record of the
//                 current costs as seen by this node.  It is
//                 constantly updated as the node gets new
//                 messages from other nodes.
/////////////////////////////////////////////////////////////////////
void printdt1( int MyNodeNumber, struct NeighborCosts *neighbor,
		struct distance_table *dtptr ) {
    int       i, j;
    int       TotalNodes = neighbor->NodesInNetwork;     // Total nodes in network
    int       NumberOfNeighbors = 0;                     // How many neighbors
    int       Neighbors[MAX_NODES];                      // Who are the neighbors

    // Determine our neighbors
    for ( i = 0; i < TotalNodes; i++ )  {
        if (( neighbor->NodeCosts[i] != INFINITY ) && i != MyNodeNumber )  {
            Neighbors[NumberOfNeighbors] = i;
            NumberOfNeighbors++;
        }
    }
    // Print the header
    printf("                via     \n");
    printf("   D%d |", MyNodeNumber );
    for ( i = 0; i < NumberOfNeighbors; i++ )
        printf("     %d", Neighbors[i]);
    printf("\n");
    printf("  ----|-------------------------------\n");

    // For each node, print the cost by travelling thru each of our neighbors
    for ( i = 0; i < TotalNodes; i++ )   {
        if ( i != MyNodeNumber )  {
            printf("dest %d|", i );
            for ( j = 0; j < NumberOfNeighbors; j++ )  {
                    printf( "  %4d", dtptr->costs[i][Neighbors[j]] );
            }
            printf("\n");
        }
    }
    printf("\n");
}    // End of printdt1
