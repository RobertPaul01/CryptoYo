#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void affine() {
	char* message;
	int message_length;
	char choice;
	int alpha, beta;
	int size = sizeof(char)*MAX_LENGTH;
	message = (char*)malloc(size);
	while (1) {
		printf("\nAffine -\nE) Encryption\nD) Decryption\nQ) Choose a different method\n");
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
		while (1) {
			printf("\nEnter the two key integers where gcd(A,%d)=1\nA: ", RANGE+1);
			scanf("%d", &alpha);
			printf("B: ");
			scanf("%d", &beta);
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF); // clear stdin
			if (is_rel_prime(alpha, RANGE+1))
				break;
			else
				printf("Those numbers aren't relatively prime.\n"); 
		}
		// remove return chars
		message[strcspn(message, "\r\n")] = 0;
		// set length variables
		message_length = strlen(message);
		// perform (en/de)crpytion
		if (choice == 'E') 		
			encrypt_affine(message, alpha, beta, message_length);	
		else if (choice == 'D')
			decrypt_affine(message, alpha, beta, message_length);	
		printf("New message is: %s\n", message);
		// clear strings
		memset(message,0,message_length);
	}
	free(message);
}
