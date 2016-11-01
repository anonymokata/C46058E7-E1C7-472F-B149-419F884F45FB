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

int convertSingleCharToInt(char romanNumeralChar);

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
