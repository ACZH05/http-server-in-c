#include <stdio.h>
#include <unistd.h>
#include "server.h"

#define BUFFER_SIZE 4096


int parseRequestLine(char *buffer, RequestLine *request_line) {
	Slice *queue[] = {&request_line->method, &request_line->path, &request_line->version};
	int cursor = 0;

	for (int i = 0; i < 3; i++) {
		queue[i]->start = &buffer[cursor];
		queue[i]->len = 0;

		while (buffer[cursor] != ' ' && buffer[cursor] != '\r') {
			if (buffer[cursor] == '\0') {
				return -1;
			}
			queue[i]->len += 1;
			cursor += 1;
		}
		cursor += 1;
	}
	return 0;
}

void handle_client(int client_socket) {
	char buffer[BUFFER_SIZE];
	int read_socket = 0;
	int request_line_status = 0;

	read_socket = read(client_socket, buffer, BUFFER_SIZE);
	printf("buffer: \n%s\n", buffer);
	
	RequestLine request_line;
	request_line_status = parseRequestLine(buffer, &request_line);
	printf("Method: %.*s\n", request_line.method.len, request_line.method.start);
	printf("Path: %.*s\n", request_line.path.len, request_line.path.start);
	printf("Version: %.*s\n", request_line.version.len, request_line.version.start);
}
