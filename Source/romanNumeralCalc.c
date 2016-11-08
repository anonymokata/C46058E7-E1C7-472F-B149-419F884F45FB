#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "convert.h"
#include "romanNumeralCalc.h"

static bool goodInput(char *firstTerm, char *secondTerm, char *returnString, int bufferSz);
static bool sumLessThan4000(int firstTerm, int secondTerm);
static bool differenceGreaterThanZero(int firstTerm, int secondTerm);

void romanAdd(char *firstNumeral, char *secondNumeral, char *sum, int bufferSz)
{
	if(!goodInput(firstNumeral, secondNumeral, sum, bufferSz))
		return;
	int firstInt = convertRomanNumeralStringToInt(firstNumeral);
	int secondInt = convertRomanNumeralStringToInt(secondNumeral);
	if (firstInt == -1 || secondInt == -1)
		return;
	if (sumLessThan4000(firstInt, secondInt))
		convertIntToRomanNumeralString(firstInt + secondInt, sum);
}

void romanSub(char *firstNumeral, char *secondNumeral, char *difference, int bufferSz)
{
	if(!goodInput(firstNumeral, secondNumeral, difference, bufferSz))
		return;
	int firstInt = convertRomanNumeralStringToInt(firstNumeral);
	int secondInt = convertRomanNumeralStringToInt(secondNumeral);
	if (differenceGreaterThanZero(firstInt, secondInt))
		convertIntToRomanNumeralString(firstInt - secondInt, difference);
}

bool goodInput(char *firstTerm, char *secondTerm, char *returnString, int bufferSz)
{
    returnString[0] = 0;
	if ((bufferSz < sizeof(char) * 16))
		return false;
	return true;
}

bool sumLessThan4000(int firstTerm, int secondTerm)
{
	if (firstTerm + secondTerm < 4000)
		return true;
	return false;
}

bool differenceGreaterThanZero(int firstTerm, int secondTerm)
{
	if (firstTerm - secondTerm > 0)
		return true;
	return false;
}
