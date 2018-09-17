//http_client by Daniel McDonough 9/1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define OPTION "-p"

//The Main Function
int main(int argc , char *argv[]) {
    int clientSock; //socket int
    int gt; //address info
    int option; //option check
    struct addrinfo thisAddress; //address
    struct addrinfo  *servinfo; //server info
    struct sockaddr_in *h; //socket struct
    //HTTP HEADER STUFF
    const char* Request1 = "GET /";
    const char* Request2 = " HTTP/1.1\r\nHost: ";
    const char* Request3 = "\r\nConnection: close\r\n\r\n";
    char* input;
    char* filepath; //filepath for http request
    char totalmessage[6000]; //buttfer for the whole concated message
    struct timeval start, end; //Start and End time checks
    float RTT; //final return time
		char * line = NULL; //Line feed
		size_t len = 0; //line feed size
    in_addr_t data; //data passed

//Check # Arguments given...
    if (argc < 3) {
        //if less than 3 print an error
        fprintf(stderr,"Error: usage is the following: ./http_client [-options] server_url port_number\n");
        exit(1);
    }

    // establish memset
    memset(&thisAddress, 0, sizeof (thisAddress));
    thisAddress.ai_family = AF_INET; //given AF_INET
    thisAddress.ai_socktype = SOCK_STREAM; //Given sockSTREAM

    //zero out the server address
    bzero((char *)&h, sizeof(h));

    // If user does not want RTT
    if (argc == 3) {
        option = 0; //option is not set

        input = strtok(argv[1], "/"); //parse the 1st input for just the URL or IP

        gt = getaddrinfo(input, argv[2], &thisAddress, &servinfo); //get addr info from URL and port

        //if failure then return an error
        if (gt != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(gt));
            return 1;
        }
    }

    // for case where user wants RTT time
    else if (argc == 4) {
      //make a clone of the given flag
        char *opt = (char*)malloc(sizeof(argv[1]));
        strcpy(opt, argv[1]);

        //check if option given is -p
        if (strcmp(opt, OPTION)) {
          //if not error
            fprintf(stderr, "Error: given option is not -p\n");
            exit(1);
        }
        option = 1; //otherwise option is checked

        input = strtok(argv[2], "/"); //parse for URL/IP
        gt = getaddrinfo(input, argv[3], &thisAddress, &servinfo); //addrinfo

//check if valid
        if (gt != 0)  {
          //return error if failure
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(gt));
            exit(1);
        }
    }

    // setup socket
    if ((clientSock = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) < 0) {
      //if less than 0 then error
        close(clientSock);
        fprintf(stderr, "Error: socket error\n");
        exit(1);
    }

    //get the init time for timer calc
    gettimeofday(&start, NULL);

    // connect to  server
    if (connect(clientSock , servinfo->ai_addr, servinfo->ai_addrlen) < 0) {
      //if less than 0 error
        close(clientSock);
        fprintf(stderr,"Error: connect error\n");
        exit(1);
    }
    //get time of day for stop
    gettimeofday(&end, NULL);
    //RTT = round trip time, therefore it is calculated on the recieve end of connection not on the return of file
    printf("Connected...\n");

    freeaddrinfo(servinfo); //FLY LIKE AN EAGLE

    // send HTTP REQUEST
    filepath = strtok(NULL, "/");
    if (filepath == NULL) {
      filepath = strdup("index.html");
      //if filepath does not exist then dont check for it
			sprintf(totalmessage, "%s%s%s%s", Request1, Request2, input, Request3);
    }else{
      //if file path exists then check for it
			sprintf(totalmessage, "%s%s%s%s%s", Request1, filepath, Request2, input, Request3);
		}


    printf("Data Send\n\n");

    // receive data
		printf("File Requested: %s\n",filepath);
		printf("URL/IP: %s\n",input);

    //you can open the socket as a file stream (mind blown)
		FILE* stream = fdopen(clientSock,"r+w");
		FILE* output = fopen(filepath,"a"); //file for outputting the request file into

  	fprintf(stream,"%s",totalmessage); //print the HTTP HEADER into the SOCKET

		int send = 0; //check for actual content...


		//check until end of EOF
		//What you also have to do is check the content length HTPP header

		while((getline(&line, &len, stream)) != -1 && line != NULL){
      //if the line has an HTML tag then start printing the response to a file
			if(strstr(line, "<") != NULL){
				send = 1; //mark to start to send to file
			}
			if(send == 0){
				printf("%s",line); //otherwise print the HTTP response to the screen
			}
			else{
			//	printf("Printing to file...\n");
					fprintf(output, "%s\n",line ); //print to fil
			}

			//note: http does not send the EOF (at least google doesnot) so instead you can feed it into a file

	//check for end of HTML tag
			if(strstr(line, "</html>") != NULL) {
				break;
		    }
			}
			printf("\nFile %s has been saved!\n",filepath );


			fclose(output); //close the doors
			fclose(stream);
			free(line); //FLY LIKE AN EAGLE
			close (clientSock); //CLOSE THE DOOR
//if option is set then print out the RTT
    if (option == 1) {
        RTT = (((end.tv_sec - start.tv_sec)*1000) + ((end.tv_usec - start.tv_usec)/1000));
        printf("RTT in milliseconds: %f\n", RTT);
    }

    return 0; //END TI
}
