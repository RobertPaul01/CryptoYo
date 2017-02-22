#include <stdio.h>
#include "affine.h"
#include "vigenere.h"
#include "common.h"

typedef enum {
	AFFINE,
	VIGENERE,
	EXIT,
	INVALID
} crypt_method;

void get_method(crypt_method* selection) {
	char choice;
	printf("What encryption do you want to use?\n");
	printf("A) Affine\n");	
	printf("B) Vigenere\n");
	printf("Q) Exit program\n");
	printf("Selection: ");
	get_choice(&choice);
	switch (choice) {
		case 'A': 
			*selection = AFFINE;
			break;
		case 'B': 
			*selection = VIGENERE;
			break;
		case 'Q':
			*selection = EXIT;
			break;
		default: 
			*selection =  INVALID;
	}
}

int main(int argc, char** argv) {		
	crypt_method method;
	int run = 1;
	while (run) {
		get_method(&method);
		switch (method) {
			case AFFINE:	
				affine();
				break;
			case VIGENERE:
				vigenere();
				break;
			case EXIT:
				printf("Exiting the program...\n");
				run = 0;
				break;		
			case INVALID:
				printf("Invalid\n");
		}
		printf("\n");
	}
	return 0;
}
