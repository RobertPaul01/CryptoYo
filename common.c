#include <stdio.h>
#include "common.h"

void getChoice(char* choice) {
	*choice = getchar();
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}
