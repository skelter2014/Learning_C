#define _GNU_SOURCE  1

#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
//#include <netinet/in.h>
//#include <netinet/ip.h>

/* https://bruinsslot.jp/post/simple-http-webserver-in-c/ */

#define PORT 8080
#define BUFFER_SIZE 1024




static int counter = 0;
int main()
{

#ifdef __USE_GNU
    printf(" use gnu defined");
#endif
    char buffer[BUFFER_SIZE] = { 0 };

    /* Create a socket */
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket == -1) {
        perror("* error* webserver (socket)");
        return -1;
    }
    printf("socket created successfully file_descriptor=[%d] \n", tcp_socket);

    /* Create a host address */
    struct sockaddr_in host_addr;
    int host_addrlen = sizeof(host_addr);

    /* Create client address */
    struct sockaddr_in client_addr;
    int client_addrlen = sizeof(client_addr);

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(tcp_socket, (struct sockaddr*)&host_addr, host_addrlen) != 0) {
        perror("webserver (bind)");
        return 1;
    }
    printf("socket successfully bound to address\n");

    /* Listen for connections */
    if (listen(tcp_socket, 2) != 0) {
        perror("webserver (listen)");
        return 1;
    }
    printf("server listening for connections\n");

    /* Infinite Loop */
    for (; ;) {

        /* Accept incoming connection */
        int newtcp_socket = accept4(tcp_socket, (struct sockaddr*)&host_addr,
            (socklen_t*)&host_addrlen, 0);
        if (newtcp_socket < 0) {
            perror("webserver (accept)");
            continue;
        }
        printf("connection accepted [%d]\n", counter++);

        /* Read REQUEST from newtcp_socket into CHAR buffer */
        int valread = read(newtcp_socket, buffer, BUFFER_SIZE);
        if (valread < 0) {
            perror("webserver (read)");
            continue;
        }

        /* Read the incoming REQUEST headers */
        char method[BUFFER_SIZE] = { 0 }, uri[BUFFER_SIZE] = { 0 }, version[BUFFER_SIZE] = { 0 };
        sscanf(buffer, "%s %s %s", method, uri, version);
        printf("[%s:%u] %s %s %s\n", inet_ntoa(client_addr.sin_addr),
            ntohs(client_addr.sin_port), method, version, uri);


        /* Read the incoming sockname */
        int sockname = getsockname(newtcp_socket, (struct sockaddr*)&client_addr,
            (socklen_t*)&client_addrlen);

        if (sockname < 0) {
            perror("webserver (getsockname)");
            continue;
        }
        printf("[%s:%u]\n", inet_ntoa(client_addr.sin_addr),
            ntohs(client_addr.sin_port));

        /* Write a canned response for now */
        time_t mytime = time(NULL);
        char* time_str = ctime(&mytime);
        time_str[strlen(time_str) - 1] = '\0';
        char* javascript = "<script>"
            "function autoRefresh()"
            "{ window.location = window.location.href;}"
            "setInterval('autoRefresh()', 5000);"
            "</script>";

        char resp[1024] = { 0 };

        sprintf(resp, "HTTP/1.0 200 OK\r\n"
            "Server: webserver-c\r\n"
            "Content-type: text/html\r\n\r\n"
            "<html><head>%s</head><h1>hello there!!</h1>"
            "<pre>%s</pre></html>\r\n", javascript, time_str);

        printf("Current Time : %s\n", time_str);

        int valwrite = write(newtcp_socket, resp, strlen(resp));
        if (valwrite < 0) {
            perror("webserver {write}");
            continue;
        }

        close(newtcp_socket);

    }

    return 0;
}
