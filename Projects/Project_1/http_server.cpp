//http_server by Daniel McDonough 9/5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

//error print message given a string
void error(const char *msg){
    perror(msg);
    exit(1);
}

//Main Function
int main(int argc, char *argv[]){

     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256]; //buffer array
     struct sockaddr_in serv_addr, cli_addr;
     int n;

     //check args
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }

     sockfd = socket(AF_INET, SOCK_STREAM, 0); //make a socket
     if (sockfd < 0){
        error("ERROR opening socket");
      }

//Setting up server info
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]); //set up port number
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     //Binding
     if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
              error("ERROR on binding");
            }
     listen(sockfd,5);
		 int clientsocket;

//infinate while loop
		 while(1){
			clientsocket = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen); //would fork here

      FILE* html_data = fopen("index.html","r");
      char response_data[64000]; //8kb
      char http_header[21] = "HTTP/1.1 200 OK\r\n\n"; //SEND HTTP RESPONSE
//while there is still data to send then... send it
      while (fgets(response_data,sizeof(response_data), html_data) != NULL){
          send(clientsocket,http_header,sizeof(http_header),0); //SEND THE FILE OVER
          printf("\"%s\"\n", response_data); //print the response data
        }
			close(clientsocket); //close the gate
		}
    return 0; //END
}
