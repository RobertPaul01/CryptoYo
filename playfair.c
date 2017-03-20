// NOTE: This program is assuming that the range of characters is A-Z.
// If that is not the range set in common.h, this cryptosystem will not
// work as intended.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playfair.h"
#include "common.h"

typedef enum {	
	NONE = 0,
	SAME_ROW = 1,
	SAME_COL = 2
} pf_rel;

// This matrix stores the indices for every letter in the playfair table
int indx[27][2] = {{0,2},{1,2},{1,3},
		{1,4},{2,0},{0,4},
		{2,1},{2,2},{1,0},{1,0},
		{2,3},{0,1},{2,4},
		{3,0},{3,1},{0,0},
		{3,2},{1,1},{3,3},
		{3,4},{4,0},{4,1},
		{4,2},{4,3},{0,3},
		{4,4}};

// The playfair table
char M[5][5] = {{'P','L','A','Y','F'},
	    	{'I','R','B','C','D'},
	    	{'E','G','H','K','M'},
	    	{'N','O','Q','S','T'},
	    	{'U','V','W','X','Z'}};

int* get_indx(char a) {
	return &indx[a-'A'][0];
}

pf_rel find_relations(char a, char b) {
	if (a == b)
		return NONE;
	int* indx_a = get_indx(a);
	int* indx_b = get_indx(b);
	if (indx_a[0] == indx_b[0]) {
		return SAME_ROW;
	} else if (indx_a[1] == indx_b[1]) {
		return SAME_COL;
	} else {
		return NONE;
	}
}

void encrypt_group(char* group) {
	pf_rel rel = find_relations(group[0], group[1]);
	int* indx_a = get_indx(group[0]);
	int* indx_b = get_indx(group[1]);
	switch (rel) {
		case NONE: {
			group[0] = M[indx_a[0]][indx_b[1]];
			group[1] = M[indx_b[0]][indx_a[1]];
			break;
		}
		case SAME_ROW: {
			group[0] = M[indx_a[0]][(indx_a[1]+1)%5];
			group[1] = M[indx_b[0]][(indx_b[1]+1)%5];
			break;
		}
		case SAME_COL: {
			group[0] = M[(indx_a[0]+1)%5][indx_a[1]];
			group[1] = M[(indx_b[0]+1)%5][indx_b[1]];
			break;
		}
	}
}

int subtract_1_m5(int x) {
	return (--x == -1 ? 4 : x);
}

void decrypt_group(char* group) {
	pf_rel rel = find_relations(group[0], group[1]);
	int* indx_a = get_indx(group[0]);
	int* indx_b = get_indx(group[1]);
	switch (rel) {
		case NONE: {
			group[0] = M[indx_a[0]][indx_b[1]];
			group[1] = M[indx_b[0]][indx_a[1]];
			break;
		}
		case SAME_ROW: {
			group[0] = M[indx_a[0]][subtract_1_m5(indx_a[1])];
			group[1] = M[indx_b[0]][subtract_1_m5(indx_b[1])];
			break;
		}
		case SAME_COL: {
			group[0] = M[subtract_1_m5(indx_a[0])][indx_a[1]];
			group[1] = M[subtract_1_m5(indx_b[0])][indx_b[1]];
			break;
		}
	}
}

void encrypt_playfair(char* message, int message_length) {
	char group[2];
	for (int i = 0; i < message_length; i++) {
		if (i%2==0) {
			group[0] = message[i];
		} else {
			group[1] = message[i];
			encrypt_group(group);
			message[i-1] = group[0];
			message[i] = group[1];
		}
	}
}

void decrypt_playfair(char* message, int message_length) {
	char group[2];
	for (int i = 0; i < message_length; i++) {
		if (i%2==0) {
			group[0] = message[i];
		} else {
			group[1] = message[i];
			decrypt_group(group);
			message[i-1] = group[0];
			message[i] = group[1];
		}
	}
}

void playfair() {

}

int main() {
	char test[] = {'E','G','M','N','F','Q','Q','M','K','N','C','\0'};
	decrypt_playfair(&test[0], 11);
	printf("%s\n", test);
	return 0;
}
