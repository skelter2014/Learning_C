#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <unistd.h>

/*
    Create a socket with the socket() system call
    Bind the socket to an address using the bind() system call. For a server socket on the Internet, an address consists of a port number on the host machine.
    Listen for connections with the listen() system call
    Accept a connection with the accept() system call. This call typically blocks until a client connects with the server.
    Send and receive data
*/

void main()
{
    int s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr = {
        AF_INET,
        0x901f,
        0
    };


    bind(s, &addr, sizeof(addr));
    listen(s, 10);
    int client_fd = accept(s, 0, 0);

    char buffer[256] = { 0 };
    recv(client_fd, buffer, 256, 0);

    // GET /file.html ...

    char* f = buffer + 5; //move the pointer 5 spaces past GET
    *strchr(f, ' ') = 0; // set the first blank space to a null
    int opened_fd = open(f, O_RDONLY);

    sendfile(client_fd, opened_fd, 0, 256);
    close(opened_fd);
    close(client_fd);

    close(s);




}