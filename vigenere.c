#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vigenere.h"
#include "common.h"

void encrypt_vigenre(char* message, char* key, int key_length, int message_length) {
	printf("encrypting: \"%s\"\n", message);
	for (int i = 0; i < message_length; i++)
		message[i] =  (((message[i]-START) + (key[i%key_length]-START))%(RANGE))+START;
}

void decrypt_vigenere(char* message, char* key, int key_length, int message_length) {
	printf("decrypting: \"%s\"\n", message);
	for (int i = 0; i < message_length; i++) {
		int new_val = (message[i]-START) - (key[i%key_length]-START);
		if (new_val < 0) 
			message[i] = END + new_val;
		else
			message[i] = (new_val%(RANGE))+START;
	}
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
		printf("\nVigenere -\nE) Encryption\nD) Decryption\nQ) Choose a different method\n");
		printf("Selection: ");
		get_choice(&choice);
		if (choice == 'Q') {
			break;
		} else if (choice != 'E' && choice != 'D') {
			printf("Please only enter E, D, or Q.\n");
			continue;
		}
		printf("What is the text? ");
		fgets(message, size, stdin);
		printf("What is the key? ");
		fgets(key, size, stdin);
		// remove return chars
		message[strcspn(message, "\r\n")] = 0;
		key[strcspn(key, "\r\n")] = 0;	
		// set length variables
		message_length = strlen(message);
		key_length = strlen(key);
		// perform (en/de)crpytion
		if (choice == 'E') 		
			encrypt_vigenre(message, key, key_length, message_length);				
		else if (choice == 'D')
			decrypt_vigenere(message, key, key_length, message_length);	
		printf("New message is: %s\n", message);
		// clear strings
		memset(message,0,message_length);
		memset(key,0,key_length);
	}
	free(message);
	free(key);
}
