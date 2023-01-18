#ifndef LOGGER_H
#define LOGGER_H

/* Data */

enum MessageLevel {
	MUTED = 0, DATA = 1, ERROR = 2
};

typedef struct Message{
	struct Message * nextMessage;
	struct Message * previousMessage;
	int messageIndex;
	enum MessageLevel messageLevel;
	char messageText[51];
} Message;

typedef struct MessageLog {
	enum MessageLevel messageTreshold;
	Message * messages;
	int logLength;
} MessageLog;

#endif