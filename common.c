#include <stdio.h>
#include "common.h"

void get_choice(char* choice) {
	*choice = getchar();
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

int gcd(long a, long b) {
	if (a > b) {
		long r = a%b;
		if (r == 0)
			return b;
		return gcd(b, r);  
	}
	return gcd(b, a);
}

int is_rel_prime(long a, long b) {
	return gcd(a, b) == 1;
}
