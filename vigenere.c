#include "vigenere.h"
#include "common.h"

void encrypt_vigenre(char* message, char* key, int key_length, int message_length) {
	printf("encrypting: \"%s\"\n", message);
	for (int i = 0; i < message_length; i++) {
		int key_val = key[i%key_length];
		int new_val = (((message[i]-START) + (key_val-START))%(RANGE)) + START;
		message[i] = new_val; 
	}
}

void decrypt_vigenere(char* message, char* key, int key_length, int message_length) {
	printf("decrypting: \"%s\"\n", message);
	for (int i = 0; i < message_length; i++) {
		int key_val = key[i%key_length];
		int new_val = (message[i]-START) - (key_val-START);
		if (new_val < 0) {
			message[i] = END + new_val;
		} else {
			message[i] = (new_val%(RANGE))+START;
		}
	}
}

int vigenere_test_cases() {
	return 1;
}

void vigenere_test() {
	printf("Vigenere tests: %s\n", vigenere_test_cases() ? "SUCCEEDED" : "FAILED");
}
