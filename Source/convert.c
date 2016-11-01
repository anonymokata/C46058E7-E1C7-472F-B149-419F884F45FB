#include <string.h>
#include <stdbool.h>
#include "convert.h"

//define all Roman Numeral char values
#define I  1
#define V  5
#define X  10
#define L  50
#define C  100
#define D  500
#define M  1000

#define ERROR -1

int convertRomanNumeralStringToInt(char *numeralString);
static int convertSingleCharToInt(char romanNumeralChar);
static int subtractIfNextCharIsSmallerThanCurrentChar(char *numeralString, int *i);

int convertRomanNumeralStringToInt(char *numeralString)
{
	int total = 0, convertedValue = 0;
	int length = strlen(numeralString) - 1;
	for (int i = length; i >= 0; i--)
	{
		convertedValue = subtractIfNextCharIsSmallerThanCurrentChar(numeralString, &i);
		if (convertedValue == ERROR)
			return ERROR;
		total += convertedValue;
	}
	return total;
 }

int subtractIfNextCharIsSmallerThanCurrentChar(char *numeralString, int *i)
{
	if (*i == 0)
		return convertSingleCharToInt(numeralString[*i]);
	int currentCharValue = convertSingleCharToInt(numeralString[*i]);
	int nextCharValue = convertSingleCharToInt(numeralString[*i - 1]);
	if (currentCharValue > nextCharValue)
	{
		*i -= 1;
		return currentCharValue - nextCharValue;
	}
	return currentCharValue;
}

int convertSingleCharToInt(char romanNumeralChar)
{
	switch (romanNumeralChar)
	{
		case 'I' :
			return I;
		case 'V' :
			return V;
		case 'X' :
			return X;
		case 'L' :
			return L;
		case 'C' :
			return C;
		case 'D' :
			return D;
		case 'M' :
			return M;
	}
	return ERROR;
}
