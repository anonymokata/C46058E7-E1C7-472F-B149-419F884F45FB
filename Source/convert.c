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
static int getNextConvertedValue(char *numeralString, int *i);
static int subtractIfNextCharIsSmallerThanCurrentChar(char *numeralString, int *i);
static bool getTwoCharacterValues(int *currentVal, int *nextVal, char *numeralString, int i);
static bool goodSubtractionPair(int pairValue);
static bool badCharValue(int currentVal, int nextVal);

int convertRomanNumeralStringToInt(char *numeralString)
{
	int total = 0, convertedValue = 0;
	int i = strlen(numeralString) - 1;
	for (; i >= 0; i--)
	{
		convertedValue = getNextConvertedValue(numeralString, &i);
		if (convertedValue == ERROR)
			return ERROR;
		total += convertedValue;
	}
	return total;
 }

int getNextConvertedValue(char *numeralString, int *i)
{
	int value = subtractIfNextCharIsSmallerThanCurrentChar(numeralString, i);
	if (value == 99)
		return ERROR;
	return value;
}

int subtractIfNextCharIsSmallerThanCurrentChar(char *numeralString, int *i)
{
	int currentCharValue = 0, nextCharValue = 0;
	if (!getTwoCharacterValues(&currentCharValue, &nextCharValue, numeralString, *i))
		return currentCharValue;
	if (badCharValue(currentCharValue, nextCharValue))
		return ERROR;
	if (currentCharValue > nextCharValue)
	{
		*i -= 1;
		return currentCharValue - nextCharValue;
	}
	return currentCharValue;
}

bool getTwoCharacterValues(int *currentVal, int *nextVal, char *numeralString, int i)
{
	*currentVal = convertSingleCharToInt(numeralString[i]);
	if (i == 0)
		return false;
	*nextVal = convertSingleCharToInt(numeralString[i - 1]);
	return true;
}

bool badCharValue(int currentVal, int nextVal)
{
	if (currentVal == ERROR || nextVal == ERROR)
		return true;
	return false;
}

bool goodSubtractionPair(int pairValue)
{
	if (pairValue == 99)
		return false;
	return true;
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
