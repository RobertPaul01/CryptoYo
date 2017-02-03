#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These will define the ASCII range used
#define START ' '
#define END '~'
#define RANGE END-START

// Define the max length of message and key
#define MAX_LENGTH 1000

int* getKeyValues(char* key, int keyLength) {
	int* keyValues = (int*) malloc(keyLength);
	for (int i = 0; i < keyLength; i++)
		keyValues[i] = (int)key[i];
	return keyValues;
}

void encrypt(char* message, char* key, int keyLength, int messageLength) {
	printf("encrypting: \"%s\"\n\n", message);
	int* keyValues = getKeyValues(key, keyLength);
	for (int i = 0; i < messageLength; i++)
		message[i] =  (((message[i]-START) + (keyValues[i%keyLength]-START))%(RANGE))+START;
	free(keyValues);
}

void decrypt(char* message, char* key, int keyLength, int messageLength) {
	printf("decrypting: \"%s\"\n\n", message);
	int* keyValues = getKeyValues(key, keyLength);
	for (int i = 0; i < messageLength; i++) {
		int newVal = (message[i]-START) - (keyValues[i%keyLength]-START);
		if (newVal < 0) 
			message[i] = END + newVal;
		else
			message[i] = (newVal%(RANGE))+START;
	}
	free(keyValues);
}

void getChoice(char* choice) {
	*choice = getchar();
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

void getInput(char* message, char* key, int size, int* messageLength, int* keyLength) {
	printf("What is the text? ");
	fgets(message, size, stdin);
	printf("What is the key? ");
	fgets(key, size, stdin);
	message[strcspn(message, "\r\n")] = 0;
	key[strcspn(key, "\r\n")] = 0;	
	*messageLength = strlen(message);
	*keyLength = strlen(key);
}

void clearInput(char* message, char* key, int messageLength, int keyLength) {
	memset(message,0,messageLength);
	memset(key,0,keyLength);
}

void freeInput(char* message, char* key) {
	free(message);
	free(key);
}

void UI() {
	char* message;
	char* key;
	int size = sizeof(char)*MAX_LENGTH;
	char choice;
	int messageLength, keyLength;
	message = (char*)malloc(size);
	key = (char*)malloc(size);
	while (1) {
		printf("Enter 0 for encryption, 1 for decryption, or 2 to exit: ");
		getChoice(&choice);
		if (choice == '2') 
			break;
		else if (choice != '0' && choice != '1') {
			printf("Please only enter 0, 1, or 2.");
			continue;
		}
		getInput(message, key, size, &messageLength, &keyLength);
		if (choice == '0') 		
			encrypt(message, key, keyLength, messageLength);				
		else if (choice == '1')
			decrypt(message, key, keyLength, messageLength);	
		printf("New message is: %s\n", message);
		clearInput(message, key, messageLength, keyLength);
	}
	freeInput(message, key);
}

int main(int argc, char** argv) {		
	UI();
	return 0;
}
