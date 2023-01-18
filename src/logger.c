#include "setup.h"

extern Panel logPanel;

MessageLog * initMessageLog(){
	MessageLog * newMessageLog = malloc(sizeof(MessageLog));
	atexit_add(newMessageLog);

	newMessageLog->logLength = 0;
	newMessageLog->messageTreshold = DATA;

	Message * newMessage = malloc(sizeof(Message));
	atexit_add(newMessage);

	newMessage->messageLevel = DATA;

	char messageText[] = "test";
	strcpy(newMessage->messageText, messageText);

	newMessageLog->logLength++;
	newMessage->messageIndex = newMessageLog->logLength;
	newMessageLog->messages = newMessage;

	return newMessageLog;
}

void addMessage(MessageLog * messageLog, enum MessageLevel messageLevel, char messageText[]){
	Message * newMessage = malloc(sizeof(Message));
	atexit_add(newMessage);

	newMessage->messageLevel = messageLevel;

	strcpy(newMessage->messageText, messageText);

	Message * previousMessage = getMessageFromIndex(messageLog, messageLog->logLength);
	newMessage->previousMessage = previousMessage;
	previousMessage->nextMessage = newMessage;

	newMessage->messageIndex = messageLog->logLength + 1;
	messageLog->logLength++;
}

Message * getMessageFromIndex(MessageLog * messageLog, int index){
	if (index < messageLog->logLength){
		Message * desiredMessage = messageLog->messages;

		while(desiredMessage->messageIndex < index)
		{
			desiredMessage = scrollForwardMessageLog(desiredMessage);
		}

		return desiredMessage;
	}
	else {
		printf("Reached over message log index.\n");
		return messageLog->messages;
	}
}

Message * scrollBackMessageLog(Message * message){
	return message->previousMessage;
}

Message * scrollForwardMessageLog(Message * message){
	return message->nextMessage;
}

void drawMessages(MessageLog * messageLog, App * app){
	int i;

	for (i = 0; i < messageLog->logLength; i++){
		Message * drawable = getMessageFromIndex(messageLog, i);
		drawUTF8Text(drawable->messageText, logPanel.x + 1, logPanel.y + 1 + i, app);
	}
}