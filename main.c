#include <stdio.h>
#include "vigenere.h"
#include "common.h"

typedef enum {
	AFFINE,
	VIGENERE,
	EXIT,
	INVALID
} cryptMethod;

void getMethod(cryptMethod* selection) {
	char choice;
	printf("What encryption do you want to use?\n");
	printf("A) Affine\n");	
	printf("B) Vigenere\n");
	printf("Q) Exit program\n");
	printf("Selection: ");
	getChoice(&choice);
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
	cryptMethod method;
	int run = 1;
	while (run) {
		getMethod(&method);
		switch (method) {
			case AFFINE:	
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
	}
	return 0;
}
