#include "local.h"

// Debug epoll_event
void debug_epoll_event(epoll_event ev){
        printf("fd(%d), ev.events:", ev.data.fd);

        if(ev.events & EPOLLIN)
                printf(" EPOLLIN ");
        if(ev.events & EPOLLOUT)
                printf(" EPOLLOUT ");
        if(ev.events & EPOLLET)
                printf(" EPOLLET ");
        if(ev.events & EPOLLPRI)
                printf(" EPOLLPRI ");
        if(ev.events & EPOLLRDNORM)
                printf(" EPOLLRDNORM ");
        if(ev.events & EPOLLRDBAND)
                printf(" EPOLLRDBAND ");
        if(ev.events & EPOLLWRNORM)
                printf(" EPOLLRDNORM ");
        if(ev.events & EPOLLWRBAND)
                printf(" EPOLLWRBAND ");
        if(ev.events & EPOLLMSG)
                printf(" EPOLLMSG ");
        if(ev.events & EPOLLERR)
                printf(" EPOLLERR ");
        if(ev.events & EPOLLHUP)
                printf(" EPOLLHUP ");
        if(ev.events & EPOLLONESHOT)
                printf(" EPOLLONESHOT ");

        printf("\n");

}
// Setup nonblocking socket
int setnonblocking(int sockfd)
{
	CHK(fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0)|O_NONBLOCK));
	return 0;
}
