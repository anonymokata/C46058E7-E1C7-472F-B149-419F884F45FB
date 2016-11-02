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
static bool getTwoCharacterValues(int *currentVal, int *nextVal, char *numeralString, int i);
static bool goodSubtractionPair(int currentCharValue, int nextCharValue);
static bool badCharValue(int currentVal, int nextVal);
static bool violatesMaxFrequencyRules(int currentValue, int nextValue);
int addFrequency(int val, int count);
static void resetFrequencies();

#define FREQUENCIES_LENGTH 13
int frequencies[FREQUENCIES_LENGTH] = {0, 0, 0, 0, 0, 0, 0};
#define MAX_FREQ_IXCM 3
#define MAX_FREQ_VLD 1
const int maximumAllowableFrequency[FREQUENCIES_LENGTH] = {MAX_FREQ_IXCM, MAX_FREQ_VLD, MAX_FREQ_IXCM, MAX_FREQ_VLD, MAX_FREQ_IXCM, MAX_FREQ_VLD, MAX_FREQ_IXCM};
const int frequencyMap[FREQUENCIES_LENGTH] = {I, V, X, L, C, D, M};
bool subtractionFlag = false;

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
	int currentCharValue = 0, nextCharValue = 0;
	if (!getTwoCharacterValues(&currentCharValue, &nextCharValue, numeralString, *i))
		return violatesMaxFrequencyRules(currentCharValue, nextCharValue) ? ERROR : currentCharValue;;
	if (badCharValue(currentCharValue, nextCharValue))
		return ERROR;
	int convertedValue = getNextConvertableValue(currentCharValue, nextCharValue, i);
	return violatesMaxFrequencyRules(currentCharValue, nextCharValue) ? ERROR : convertedValue;
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

int getNextConvertableValue(int currentCharValue, int nextCharValue, int *i)
{
	if (currentCharValue > nextCharValue)
	{
		if (!goodSubtractionPair(currentCharValue, nextCharValue))
			return ERROR;
		subtractionFlag = true;
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

bool violatesMaxFrequencyRules(int currentCharValue, int nextCharValue)
{
	int index = -1;
	if (subtractionFlag)
	{
		index = addFrequency(nextCharValue, MAX_FREQ_IXCM);
		if (frequencies[index] > maximumAllowableFrequency[index])
			return true;
	}
	subtractionFlag = false;
	index = addFrequency(currentCharValue, MAX_FREQ_VLD);
	if (frequencies[index] > maximumAllowableFrequency[index])
		return true;
	return false;
}

int addFrequency(int val, int count)
{
	for (int i = 0; i < FREQUENCIES_LENGTH; i++)
		if (frequencyMap[i] == val)
			{
				frequencies[i] += count;
				return i;
			}
}

void resetFrequencies()
{
	for (int i = 0; i < FREQUENCIES_LENGTH; i++)
		frequencies[i] = 0;
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
