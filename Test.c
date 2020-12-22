#include "Test.h"
#include "StateMachine.h"
#include <stdbool.h>

bool correctCases()
{
	char string1[] = "AA1%+D@MA9-8.O";
	if (correctString(string1) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool wrongCase()
{
	char string1[] = "A@A";
	if (correctString(string1) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool testStateMachine()
{
	return (wrongCase() && correctCases());
}