#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

#define PORT 8080
#define BUFFER_SIZE 4096

int main() {
	int tcp_socket = 0;
	int bind_socket = 0;
	int listen_socket = 0;
	int client_socket = 0;
	
	tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (tcp_socket == -1) {
		perror("Error: ");
		exit(1);
	}

	struct sockaddr_in address;
	socklen_t addr_len = sizeof(address);
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.s_addr = INADDR_ANY;

	bind_socket = bind(tcp_socket, (struct sockaddr *) &address, sizeof(address));

	if (bind_socket == -1) {
		perror("Error: ");
		exit(1);
	}

	listen_socket = listen(tcp_socket, 10);

	if (listen_socket == -1) {
		perror("Error: ");
		exit(1);
	}

	while (true) {
		printf("Waiting Connection...\n");
		client_socket = accept(tcp_socket, NULL, NULL);
		printf("Accept!\n");
	}
	return 0;
}
