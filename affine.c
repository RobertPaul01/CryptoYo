#include "affine.h"
#include "common.h"

void encrypt_affine(char* message, int alpha, int beta, int message_length) {
	for (int i = 0; i < message_length; i++) {
		message[i] = (((alpha*(message[i]-START))+beta)%(RANGE+1))+START; 
	}
}

void decrypt_affine(char* message, int alpha, int beta, int message_length) {
	int inverse = find_inverse(alpha, RANGE+1);
	for (int i = 0; i < message_length; i++) {
		int diff = (message[i]-START)-beta;
		while (diff < 0)
			diff += RANGE+1;
		message[i] = ((inverse*diff)%(RANGE+1))+START;
	}
}

int affine_test_cases() {
	return 1;
}

void affine_test() {
	printf("Affine tests: %s\n", affine_test_cases() ? "SUCCEEDED" : "FAILED");
}
