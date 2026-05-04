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

int parseRequestLine(char *, RequestLine *);
void handle_client(int);

#endif
