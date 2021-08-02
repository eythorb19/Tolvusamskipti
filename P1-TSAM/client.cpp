//
// TSAM-409 Assignment 1
//
// Client that sends "Hello world to server"
//
// Compile: g++ -Wall -std=c++11 client.cpp
//
// Command line: ./client <server ip address> < server host>
//
// Author: Eyþór Óli Borgþórsson;
//

#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <string>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h> 
#include<errno.h>

using namespace std;

int main(int argc, char const *argv[]) {

    //Initialize values
    sockaddr_in server_addr;        // Address settings
    struct hostent *server;         // Structure that describes an Internet host
    string ip_addr;                 // Server IP address
    int sock;                       // Socket
    int network_addr;               // IPv4/IPv6 address in network byte order / numeric binary
    int connection;                 // Connection to server
    int request;                    // Request to server
    int resp;                       // Response from server

    //Create a new socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("Failed to open socket. %s\n");
		return(-1);
    }
    else {
        printf("Success: Socket opened \n");
    }

	// Set values for connection
    server_addr.sin_family = AF_INET;               // IPv4 internet protocol family
    server_addr.sin_port = htons(atoi(argv[2]));    // Port. Convert unsigned short int from host byte order to network byte order.
    ip_addr = argv[1];                              // IP address argument

    // Protocol and IP address assigned
    network_addr = inet_pton(AF_INET, ip_addr.c_str(), &server_addr.sin_addr);

    // If IP address of server is unknown
    if(network_addr <= 0) {
        perror("Failed to set socket address. IP unknown");
        return(-1);
    }

    // IP address known
    else {
        printf("IP address known");
    }

    // Connect to remote address
    connection = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // Connection fail
    if (connection < 0) {
        perror("Could not connect to server. \n");
        return(-1);
    }
    // Connection success
    else {
        printf("Connected to server! \n");
    }

    // Send request to server
    request = send(sock, "Hello world", sizeof("Hello world") -1, 0);

    // Request fail
    if (request == -1) {
        perror("Unable to send request to server.");
        exit(0);
    }
    // Request success
    else {
        printf("Hello world sent to server. \n");
    }
}