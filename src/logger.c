#include "setup.h"

extern Panel logPanel;

void insertFirst(MessageLog * messageLog, int key, char data[51]){
	Message * link = (Message *) malloc(sizeof(Message));
	atexit_add(link);

	link->key = key;

	strcpy(link->text, data);

	link->next = messageLog->head;

	messageLog->head = link;
}

bool isEmpty(MessageLog * messageLog){
	return messageLog->head == NULL;
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
	Message * ptr = messageLog->head;

	while(ptr != NULL){
		drawUTF8Text(ptr, logPanel.x + 1, logPanel.y + 1, app);
		ptr = ptr->next;
	}
}
