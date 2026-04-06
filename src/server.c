#include <stdio.h>
#include <unistd.h>
#include "server.h"

#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
	char buffer[BUFFER_SIZE];
	int read_socket = 0;

	read_socket = read(client_socket, buffer, BUFFER_SIZE);
	printf("buffer: \n%s", buffer);

}
