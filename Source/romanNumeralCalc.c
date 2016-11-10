#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "convert.h"
#include "romanNumeralCalc.h"

#define ERROR -1

static bool goodInput(int firstTerm, int secondTerm, int bufferSize, char *returnString);
static void goodDifference(int firstTerm, int secondTerm, char *difference);
static void goodSum(int firstTerm, int secondTerm, char *sum);

void romanAdd(char *firstNumeral, char *secondNumeral, char *sum, int bufferSz)
{
	int firstInt = convertRomanNumeralStringToInt(firstNumeral);
	int secondInt = convertRomanNumeralStringToInt(secondNumeral);
	if (!goodInput(firstInt, secondInt, bufferSz, sum))
		return;
	goodSum(firstInt, secondInt, sum);
}

void romanSub(char *firstNumeral, char *secondNumeral, char *difference, int bufferSz)
{
	int firstInt = convertRomanNumeralStringToInt(firstNumeral);
	int secondInt = convertRomanNumeralStringToInt(secondNumeral);
	if (!goodInput(firstInt, secondInt, bufferSz, difference))
		return;
	goodDifference(firstInt, secondInt, difference);
}

bool goodInput(int firstTerm, int secondTerm, int bufferSize, char *returnString)
{
	returnString[0] = 0;
	if (bufferSize < sizeof(char) * 16)
		return false;
	if (firstTerm == ERROR || secondTerm == ERROR)
		return false;
	return true;
}

void goodSum(int firstTerm, int secondTerm, char *sum)
{
    if (firstTerm + secondTerm < 4000)
        convertIntToRomanNumeralString(firstTerm + secondTerm, sum);
}

void goodDifference(int firstTerm, int secondTerm, char *difference)
{
	if (firstTerm - secondTerm > 0)
		convertIntToRomanNumeralString(firstTerm - secondTerm, difference);
}

