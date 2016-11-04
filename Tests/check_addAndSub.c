/*
 * check_addAndSub.c
 *
 *  Created on: Nov 3, 2016
 *      Author: brad
 */
#include <check.h>
#include "check_addAndSub.h"
#include "Source/romanNumeralCalc.h"

START_TEST(test_addRomanNumeralStrings_IV_CMIX)
{
	char *concatNumeralString[16];
	romanAdd("IV", "CMIX", concatNumeralString, sizeof(concatNumeralString));
	ck_assert_str_eq(concatNumeralString, "CMXIII");
}
END_TEST

START_TEST(test_subRomanNumeralStrings_CXC_X)
{
	char *concatNumeralString[16];
	romanSub("CXC", "X", concatNumeralString, sizeof(concatNumeralString));
	ck_assert_str_eq(concatNumeralString, "CLXXX");
}
END_TEST

TCase * addAndSub_tcase(void)
{
	TCase *tc_addAndSub = tcase_create("Core");

	tcase_add_test(tc_addAndSub, test_addRomanNumeralStrings_IV_CMIX);

	tcase_add_test(tc_addAndSub, test_subRomanNumeralStrings_CXC_X);
	return tc_addAndSub;
}
