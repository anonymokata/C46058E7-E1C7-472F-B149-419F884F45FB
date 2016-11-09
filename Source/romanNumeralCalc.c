#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "convert.h"
#include "romanNumeralCalc.h"

static void nullString(char *returnString);
static bool sumLessThan4000(int firstTerm, int secondTerm);
static void goodDifference(int firstTerm, int secondTerm, char *difference);

void romanAdd(char *firstNumeral, char *secondNumeral, char *sum, int bufferSz)
{
    sum[0] = 0;
	if (bufferSz < sizeof(char) * 16)
		return nullString(sum);
	int firstInt = convertRomanNumeralStringToInt(firstNumeral);
	int secondInt = convertRomanNumeralStringToInt(secondNumeral);
	if (firstInt == -1 || secondInt == -1)
		return nullString(sum);
	if (sumLessThan4000(firstInt, secondInt))
		convertIntToRomanNumeralString(firstInt + secondInt, sum);
}

void romanSub(char *firstNumeral, char *secondNumeral, char *difference, int bufferSz)
{
    difference[0] = 0;
	if(bufferSz < sizeof(char) * 16)
		return nullString(difference);
	int firstInt = convertRomanNumeralStringToInt(firstNumeral);
	int secondInt = convertRomanNumeralStringToInt(secondNumeral);
	if (firstInt == -1 || secondInt == -1)
		return nullString(difference);
	goodDifference(firstInt, secondInt, difference);
}

bool sumLessThan4000(int firstTerm, int secondTerm)
{
	if (firstTerm + secondTerm < 4000)
		return true;
	return false;
}

void goodDifference(int firstTerm, int secondTerm, char *difference)
{
	if (firstTerm - secondTerm > 0)
		convertIntToRomanNumeralString(firstTerm - secondTerm, difference);
	else
		nullString(difference);
}

void nullString(char *returnString)
{
	returnString[0] = '\0';
}
