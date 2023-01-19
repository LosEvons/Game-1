#ifndef LOGGER_H
#define LOGGER_H

/* Data */

enum MessageLevel {
	MUTED = 0, ERROR = 1, SYSTEM_MESSAGE = 2, DATA = 3
};

typedef struct Message{
	char text[51];
	enum MessageLevel level;
	int key;
	struct Message * next;
} Message;


typedef struct MessageLog {
	enum MessageLevel treshold;
	Message *head;
	Message *current;
} MessageLog;

#endif