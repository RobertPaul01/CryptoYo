#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vigenere.h"
#include "common.h"

void encrypt(char* message, char* key, int key_length, int message_length) {
	printf("encrypting: \"%s\"\n", message);
	for (int i = 0; i < message_length; i++)
		message[i] =  (((message[i]-START) + (key[i%key_length]-START))%(RANGE))+START;
}

void decrypt(char* message, char* key, int key_length, int message_length) {
	printf("decrypting: \"%s\"\n", message);
	for (int i = 0; i < message_length; i++) {
		int new_val = (message[i]-START) - (key[i%key_length]-START);
		if (new_val < 0) 
			message[i] = END + new_val;
		else
			message[i] = (new_val%(RANGE))+START;
	}
}

void getInput(char* message, char* key, int size, int* message_length, int* key_length) {
	printf("What is the text? ");
	fgets(message, size, stdin);
	printf("What is the key? ");
	fgets(key, size, stdin);
	message[strcspn(message, "\r\n")] = 0;
	key[strcspn(key, "\r\n")] = 0;	
	*message_length = strlen(message);
	*key_length = strlen(key);
}

void clearInput(char* message, char* key, int message_length, int key_length) {
	memset(message,0,message_length);
	memset(key,0,key_length);
}

void freeInput(char* message, char* key) {
	free(message);
	free(key);
}

void vigenere() {
	char* message;
	char* key;
	int size = sizeof(char)*MAX_LENGTH;
	char choice;
	int message_length, key_length;
	message = (char*)malloc(size);
	key = (char*)malloc(size);
	while (1) {
		printf("Enter 0 for encryption, 1 for decryption, or 2 to choose a different method: ");
		getChoice(&choice);
		if (choice == '2') 
			break;
		else if (choice != '0' && choice != '1') {
			printf("Please only enter 0, 1, or 2.\n");
			continue;
		}
		getInput(message, key, size, &message_length, &key_length);
		if (choice == '0') 		
			encrypt(message, key, key_length, message_length);				
		else if (choice == '1')
			decrypt(message, key, key_length, message_length);	
		printf("New message is: %s\n\n", message);
		clearInput(message, key, message_length, key_length);
	}
	freeInput(message, key);
}
