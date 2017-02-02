#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These will define the ASCII range used
#define START ' '
#define END '~'
#define RANGE END-START

int* getKeyValues(char* key, int keyLength) {
	int* keyValues = (int*) malloc(keyLength);
	for (int i = 0; i < keyLength; i++)
		keyValues[i] = (int)key[i];
	return keyValues;
}

void encrypt(char* message, char* key, int keyLength) {
	printf("encrypting: \"%s\"\n\n", message);
	
	int* keyValues = getKeyValues(key, keyLength);

	// begin shifting original string
	int messageLength = strlen(message);
	for (int i = 0; i < messageLength; i++)
		message[i] =  (((message[i]-START) + (keyValues[i%keyLength]-START))%(RANGE))+START;
	
	// print encrypted message
	printf("encrypted message: %s\n", message);
}

void decrypt(char* message, char* key, int keyLength) {
	printf("decrypting: \"%s\"\n\n", message);
	
	int* keyValues = getKeyValues(key, keyLength);
	
	// begin shifting original string
	int messageLength = strlen(message);
	for (int i = 0; i < messageLength; i++) {
		int newVal = (message[i]-START) - (keyValues[i%keyLength]-START);
		if (newVal < 0) 
			message[i] = END + newVal;
		else
			message[i] = (newVal%(RANGE))+START;
	}
	
	// print decrypted message
	printf("decrypted message: %s\n", message);
}

int main(int argc, char** argv) {		
	char message[256];
	char key[256];
	char choice;

	// get choice
	printf("Enter 0 for encryption or 1 for decryption: ");
	choice = getchar();
	
	// clear the input buffer of newline
 	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);

	// get input
	printf("What is the text? ");
	fgets(message, sizeof(message), stdin);
	printf("What is the key? ");
	fgets(key, sizeof(key), stdin);
	
	// remove new line chars from input	
	message[strcspn(message, "\r\n")] = 0;
	key[strcspn(key, "\r\n")] = 0;	

	// encrypt/decrypt
	if (choice == '1') 		
		decrypt(&message[0], &key[0], strlen(&key[0]));				
	else
		encrypt(&message[0], &key[0], strlen(&key[0]));

	return 0;
}
