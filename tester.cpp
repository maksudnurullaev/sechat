#include "local.h"
#include "utils.h"

using namespace std;

// to keep message from server
char message[BUF_SIZE];

// for debuf mode
int DEBUG_MODE = 0;

// to store client's sockets list
list<int> list_of_clients;

// to keep result of different functions
int res;

// to calculate the execution time of a program
clock_t tStart;

int main(int argc, char *argv[])
{
    // *** Define debug mode
    //     any additional parameres on startup
    //     i.e. like './server f' or './server debug'
    //     we will switch to switch to debug mode(very simple anmd useful)
    if(argc > 1) DEBUG_MODE = 1;

    if(DEBUG_MODE){
        printf("Debug mode is ON!\n");
        printf("MAIN: argc = %d\n", argc);
        for(int i=0; i<argc; i++)
            printf(" argv[%d] = %s\n", i, argv[i]);
    }else printf("Debug mode is OFF!\n");

    // *** Define values
    //     connetion with server
    int sock;
    
    //     define address & port of server
    struct sockaddr_in addr;
    addr.sin_family = PF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_HOST);
    
    // setup start time
    tStart = clock();

    // create EPOLL_SIZE connections with server
    for(int i=0 ; i<EPOLL_SIZE; i++){

               // create new socket connection with server 
               CHK2(sock,socket(PF_INET, SOCK_STREAM, 0));
               CHK(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0);
               list_of_clients.push_back(sock);
               if(DEBUG_MODE) printf("Create new test client with fd: %d\n", sock);

               // Get welcome messge from server!
               bzero(&message, BUF_SIZE);
               CHK2(res,recv(sock, message, BUF_SIZE, 0));
               printf("%s\n", message);
    }
   
    // close all connections
    list<int>::iterator it;
    for(it = list_of_clients.begin(); it != list_of_clients.end() ; it++)
       close(*it);

    // print statistics 
    printf("Test passed at: %.2f second(s)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC); 
    printf("Total server connections was: %d\n", EPOLL_SIZE);
    
    return 0;
}

