#include <stdio.h>
#include "common.h"

void get_choice(char* choice) {
	*choice = getchar();
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}
