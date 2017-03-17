#include <stdio.h>
#include "common.h"

void get_choice(char* choice) {
	*choice = getchar();
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

int gcd(long a, long b) {
	if (a >= b) {
		long r = a%b;
		if (r == 0)
			return b;
		return gcd(b, r);  
	}
	return gcd(b, a);
}

// Using GEA would be better here, but this is fine for now
int find_inverse(long a, long b) {
	for (long i = 0; i < b; i++) {
		if ((a*i)%b == 1)
			return i;
	}
	return -1;
}

int is_rel_prime(long a, long b) {
	return gcd(a, b) == 1;
}
