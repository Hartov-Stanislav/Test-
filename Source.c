#include <stdio.h>
#include "StateMachine.h"
#include <stdbool.h>
#include "Test.h"

#define MAX 100

int main()
{
	if (testStateMachine() == false)
	{
		return 1;
	}
	FILE* input = fopen("1.txt", "r");
	if (input == NULL)
	{
		printf("Cannot open file.\n");
		return NULL;
	}
	char* buffer = malloc(sizeof(char) * MAX);
	while (!feof(input)) {
		const int readBytes = fscanf(input, "%s", buffer);
		if (readBytes < 0) {
			break;
		}
	}
	fclose(input);
	if (correctString(buffer) == 0)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	free(buffer);
	return 0;
}