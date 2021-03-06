#Objective

This library's primary focus is to provide the user with 2 portable functions, namely add and sub, which may be used to perform addition or subtraction, respectively, on two Roman numerals of a char* type, in the C programming language.

#A few points of interest :

    The maximum allowable value for any numeral string is 3999.
    The minimum allowable value for any numeral string is 1.
    any non-valid input results in add() or sub() setting its return string to the empty string
    Valid Roman numerals are : I, V, X, L, C, D, M (case sensitive)
    A maximum frequency of 3 consecutive characters exists for I, X, C, M (IE. IIII is invalid)
    A maximum frequency of 1 exists for characters V, L, D (IE, DD is invalid)
    Modern Roman numeral conventions are adhered to. (IE. IL is an invalid character pair. 49 should be written as XLIX)
    More on modern Roman numeral conventions can be found here: http://sizes.com/numbers/roman_numerals.htm

#API:

!!!  **  *(Note: The size of the char array for sum or difference must be >= 16)*  **  !!

    add(char *term1, char *term2, char *sum, int bufferSizeOfSum)
        add takes two Roman numeral variables, in char* format, adds them, then mutates sum to return the value
        add sets sum to the empty string for any non-valid input, including numeral strings that do not adhere to modern convention
        add sets sum to the empty string if the sum exceeds 3999

    sub(char *term1, char *term2, char *difference, int bufferSizeOfDifference)
        sub takes two Roman numeral variables, in char* format, subtracts them, then mutates difference to return the value
        sub subtracts term2 from term1 | sub("XX", "V", diff, buff) sets difference to "XV" | (20 - 5) = 15
        sub sets difference to the empty string for any non-valid input
        sub sets difference to the empty string if the difference is zero or negative

#Installation  
\# download from the github repository, install in preferred dir  
directory structure:  
|RomanNumeralCalc2ndTry-master  
---|Makefile  
---|README.md  
---|source  
------|Makefile  
------|convert.c  
------|convert.h  
------|romanNumeralCalc.c  
------|romanNumeralCalc.h  
---|tests  
------|Makefile  
------|check_convert.c  
------|check_convert.h  
------|check_addAndSub.c  
------|check_addAndSub.h  
------|check_romanNumeralCalc.c  
------|check_romanNumeralCalc.h  
to build all objects and run all tests from command line:  
../RomanNumeralCalc2ndTry-master$ make check  

#Example:

\#include "romanNumeralCalc.h"  
\#define ARRAY_SIZE 16  
char sum[ARRAY_SIZE];  
char \*term1 = "XXVI";   
char \*term2 = "C";  
int buffSize = sizeof(char) \* ARRAY_SIZE;  
romanAdd(term1, term2, sum, buffSize);//sets sum to "CXXVI"  



