#include "StateMachine.h"

int selectCase(const char* string, const int pos)
{
	if ((string[pos] >= 'A') && (string[pos] <= 'Z'))
	{
		return 1;
	}
	if ((string[pos] >= '0') && (string[pos] <= '9'))
	{
		return 2;
	}
	if ((string[pos] == '_') || (string[pos] == '%') || (string[pos] == '+'))
	{
		return 3;
	}
	if (string[pos] == '.')
	{
		return 6;
	}
	if (string[pos] == '-')
	{
		return 4;
	}
	if (string[pos] == '@')
	{
		return 5;
	}
	if ((string[pos]) == '\0')
	{
		return 10;
	}
	else
	{
		return 13;
	}
}

int correctString(const char* buffer)
{
	int state = 1;
	int pos = 0;
	while (state != 0)
	{
		switch (state)
		{
		case 1:
			state = selectCase(buffer, pos);
			pos++;
			// [A-Z0-9._%+-] - stay here
			if ((state == 2) || (state == 3) || (state == 6) || (state == 4))
			{
				state = 1;
			}
			// [@] - change case
			if (state == 5)
			{
				state = 2;
			}
			// isn't correct
			if (state > 2)
			{
				printf("false");
				return 1;
			}
			break;
		case 2:
			state = selectCase(buffer, pos);
			pos++;
			// [A-Z0-9-] - stay here
			if ((state == 1) || (state == 4))
			{
				state = 2;
			}
			// [/.] - change case
			if (state == 6)
			{
				state = 3;
			}
			// isn't correct
			if (state > 3)
			{
				printf("false");
				return 1;
			}
			break;
		case 3:
			state = selectCase(buffer, pos);
			pos++;
			// end of string
			if ((state == 10) && (selectCase(buffer, pos - 2) == 1))
			{
				printf("true");
				return 0;
			}
			// [A-Z] - stay here
			if (state == 1)
			{
				state = 3;
			}
			else
			{
				printf("false");
				return 1;
			}
			break;
		default:
			printf("false");
			return 0;
		}
	}
}
