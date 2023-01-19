#include "setup.h"

extern Panel logPanel;

void insertFirst(MessageLog * messageLog, int key, char data[51], enum MessageLevel level){
	Message * link = (Message *) malloc(sizeof(Message));
	atexit_add(link);

	link->key = key;
	link->level = level;

	strcpy(link->text, data);

	link->next = messageLog->head;

	messageLog->head = link;
}

void addLog(MessageLog * messageLog, char data[51], enum MessageLevel level){
	Message * link = (Message *) malloc(sizeof(Message));
	atexit_add(link);

	link->key = getLogLength(messageLog);
	link->level = level;

	strcpy(link->text, data);

	link->next = messageLog->head;

	messageLog->head = link;
}

bool isEmpty(MessageLog * messageLog){
	return messageLog->head == NULL;
}

int getLogLength(MessageLog * messageLog){
	int length = 0;

	Message * current = messageLog->head;

	while (current != NULL){
		length++;
		current = current->next;
	}

	return length;
}

Message * find(MessageLog * messageLog, int key){
	Message * current = messageLog->head;

	if (messageLog->head == NULL){
		return NULL;
	}

	while(current->key != key){
		if (current->next == NULL){
			return NULL;
		} else {
			current = current->next;
		}
	}

	return current;
}

void drawMessages(MessageLog * messageLog, App * app){
	int tempHead = 0; // Index of head when log doesn't fit in window
	int messagesDrawn = 0; // How many messages have already been drawn (used for offset)
	int passedMessages = 0; // How many messages weren't drawn (used to remove spaces left by undrawn indexes)
	int maxDisplayedMessages = LOG_PANEL_HEIGHT + 2; // How many lines fit into our log panel
	int logLength = getLogLength(messageLog);

	Message * ptr = NULL; // Current message being evaluated for drawing

	if (logLength > maxDisplayedMessages){
		tempHead = logLength - 1; // Index of the most recent message
		ptr = find(messageLog, tempHead); // Find message from index
	}
	else {
		ptr = messageLog->head; // Use start of log
	}

	while(ptr != NULL && messagesDrawn < maxDisplayedMessages){
		if (ptr->level >= messageLog->treshold){
			drawUTF8Log(ptr, logPanel.x + 1, VIRTUAL_SCREEN_HEIGHT - 1, messagesDrawn, app);
			messagesDrawn++;
		}
		else if (ptr->level < messageLog->treshold){
			passedMessages++;
		}

		ptr = ptr->next;
	}
}