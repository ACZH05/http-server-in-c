#ifndef SERVER_H
#define SERVER_H

typedef struct {
	char *start;
	int len;
} Slice;

typedef struct {
	Slice method;
	Slice path;
	Slice version;
} RequestLine;

void send_response(int, char *, char *, char *);
int parseRequestLine(char *, RequestLine *);
void handle_client(int);

#endif
