#ifndef LOGGER_H
#define LOGGER_H

/* Data */

enum MessageLevel {
	MUTED = 0, DATA = 1, ERROR = 2
};

typedef struct Message{
	char text[51];
	int key;
	struct Message * next;
} Message;


typedef struct MessageLog {
	enum MessageLevel treshold;
	Message *head;
	Message *current;
} MessageLog;

#endif