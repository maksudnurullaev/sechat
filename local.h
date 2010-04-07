#ifndef _SCHAT_LOCAL_H_
#define _SCHAT_LOCAL_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <list>
#include <time.h>

// Default buffer size
#define BUF_SIZE 1024

// Default port
#define SERVER_PORT 44444

// seChat server ip, you should change it to your own server ip address
#define SERVER_HOST "192.168.34.15"

// Default timeout - http://linux.die.net/man/2/epoll_wait
#define EPOLL_RUN_TIMEOUT -1

// Count of connections that we are planning to handle (just hint to kernel)
#define EPOLL_SIZE 10000

// First welcome message from server
#define STR_WELCOME "Welcome to seChat! You ID is: Client #%d"

// Format of message population
#define STR_MESSAGE "Client #%d>> %s"

// Warning message if you alone in server
#define STR_NOONE_CONNECTED "Noone connected to server except you!"

// Commad to exit
#define CMD_EXIT "EXIT"

// Macros - exit in any error (eval < 0) case
#define CHK(eval) if(eval < 0){perror("eval"); exit(-1);}

// Macros - same as above, but save the result(res) of expression(eval) 
#define CHK2(res, eval) if((res = eval) < 0){perror("eval"); exit(-1);}

// Preliminary declaration of functions
int setnonblocking(int sockfd);
void debug_epoll_event(epoll_event ev);
int handle_message(int new_fd);
int print_incoming(int fd);

#endif
