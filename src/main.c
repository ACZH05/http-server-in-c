#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "server.h"

#define PORT 8080

int main() {
	int tcp_socket = 0;
	int option_socket = 0;
	int opt = 1;
	int bind_socket = 0;
	int listen_socket = 0;
	int client_socket = 0;
	int read_socket = 0;
	
	tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (tcp_socket == -1) {
		perror("Error");
		exit(1);
	}

	struct sockaddr_in address;
	socklen_t addr_len = sizeof(address);
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.s_addr = INADDR_ANY;

	option_socket = setsockopt(tcp_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	bind_socket = bind(tcp_socket, (struct sockaddr *) &address, sizeof(address));

	if (bind_socket == -1) {
		perror("Error");
		exit(1);
	}

	listen_socket = listen(tcp_socket, 10);

	if (listen_socket == -1) {
		perror("Error");
		exit(1);
	}

	while (1) {
		printf("Waiting Connection...\n");
		client_socket = accept(tcp_socket, (struct sockaddr *) &address, &addr_len);
		handle_client(client_socket);
	}
	return 0;
}
