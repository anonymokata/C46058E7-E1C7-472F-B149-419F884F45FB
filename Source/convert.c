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
static int calculateResult(int currentCharValue, int nextCharValue, int *i);
static bool getTwoCharacterValues(int *currentVal, int *nextVal, char *numeralString, int i);
static bool goodSubtractionPair(int currentCharValue, int nextCharValue);
static bool badCharValue(int currentVal, int nextVal);
static bool resultDoesNotViolateFrequencyConstraints(int convertedValue);
static bool violatesMaxFrequencyRules(int convertedValue);
static void resetFrequencies();

#define CONVERTEDVALUEFREQUENCIES_LENGTH 7
int convertedValueFrequencies[CONVERTEDVALUEFREQUENCIES_LENGTH] = {0, 0, 0, 0, 0, 0, 0};
const int convertedValueIndex[CONVERTEDVALUEFREQUENCIES_LENGTH] = {I, V, X, L, C, D, M};
#define MAX_FREQ_IXC 3
#define MAX_FREQ_VLD 1
#define MAX_FREQ_M 6
int maximumAllowableFrequency[CONVERTEDVALUEFREQUENCIES_LENGTH] = {MAX_FREQ_IXC, MAX_FREQ_VLD, MAX_FREQ_IXC, MAX_FREQ_VLD, MAX_FREQ_IXC, MAX_FREQ_VLD, MAX_FREQ_M};

int convertRomanNumeralStringToInt(char *numeralString)
{
	resetFrequencies();
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
	int currentCharValue = 0, nextCharValue = 0, result = 0;
	if (!getTwoCharacterValues(&currentCharValue, &nextCharValue, numeralString, *i))
		return currentCharValue;
	if (badCharValue(currentCharValue, nextCharValue))
		return ERROR;
	int convertedValue = calculateResult(currentCharValue, nextCharValue, i);
	if (violatesMaxFrequencyRules(convertedValue))
		return ERROR;
	return convertedValue;
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

int calculateResult(int currentCharValue, int nextCharValue, int *i)
{
	if (currentCharValue > nextCharValue)
	{
		if (!goodSubtractionPair(currentCharValue, nextCharValue))
			return ERROR;
		*i -= 1;
		return currentCharValue - nextCharValue;
	}
	return currentCharValue;
}

bool goodSubtractionPair(int currentCharValue, int nextCharValue)
{
	if (nextCharValue == I || nextCharValue == X || nextCharValue == C)
		{
			int firstDividedBySecond = currentCharValue / nextCharValue;
			if (firstDividedBySecond == 5 || firstDividedBySecond == 10)
				return true;
		}
	return false;
}

bool violatesMaxFrequencyRules(int convertedValue)
{
	for (int i = 0; i < CONVERTEDVALUEFREQUENCIES_LENGTH; i++)
		if (convertedValueIndex[i] == convertedValue)
			{
				convertedValueFrequencies[i]++;
				if (convertedValueFrequencies[i] > maximumAllowableFrequency[i])
					return true;
				break;
			}
	return false;
}

void resetFrequencies()
{
	for (int i = 0; i < CONVERTEDVALUEFREQUENCIES_LENGTH; i++)
		convertedValueFrequencies[i] = 0;
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
