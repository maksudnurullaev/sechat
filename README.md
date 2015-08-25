By the time of writing this program I could not find proper information about epoll with good example or tutorial, and I started to develop my version of "Simple Epoll Chat"(seChat) based on epoll to investigate it. Here I wanted to share my own results and impressions of the epoll and to help others who wants to develop/test/investigate epoll too.

General task & notes
Our task - create chat with simple parts, as:

server
Listens to a predefined ip address and port, and "register" all incoming clients;
Identifies each new client when connecting;
Receives a message from any client, and sends to all but the "sender";
client can receive and send messages simultaneously;
tester - a simple test program to load on the server with a large number of simultaneous connections.
Several additional notes:

epoll is used to control the events of new messages for server and client application;
For all unknown commands and functions consult to manual, everything is well described;
For simplicity:
I'm not using the "normal" error handlers, and any exceptions call exit code (which very useful solution at the stage of coding and testing!). Ideally, the program should handle the error and try to return to the "normal job state", but I tried to be keep code as simple at is possible;
I hardcoded ip address and port - i'm lazy :-), but you free to change source to run program like './server ip port' or './client 192.168.1.1:1234'.
Requirements
OS Linux (kernel version >= 2.5.66)
GNU gcc
GNU make
Conclusion
This screenshot shows the result of tester application and more expressive then thousands of worlds.
