#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affine.h"
#include "common.h"

/*
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

void get_input(char* message, char* key, int size, int* message_length, int* key_length) {
	printf("What is the text? ");
	fgets(message, size, stdin);
	printf("What is the key? ");
	fgets(key, size, stdin);
	message[strcspn(message, "\r\n")] = 0;
	key[strcspn(key, "\r\n")] = 0;	
	*message_length = strlen(message);
	*key_length = strlen(key);
}

void clear_input(char* message, char* key, int message_length, int key_length) {
	memset(message,0,message_length);
	memset(key,0,key_length);
}

void free_input(char* message, char* key) {
	free(message);
	free(key);
}*/

void affine() {

}
