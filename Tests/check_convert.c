#include "check_convert.h"
#include <check.h>

START_TEST(test_convertSingleRomanNumeralCharToInt)
{
	ck_assert_int_eq(convertSingleCharToInt('I'), 1);
}
END_TEST

START_TEST(test_convertRomanNumeralStringToInt_VI)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("VI"), 6);
}
END_TEST

Suite * convert_suite(void)
{
	Suite *s;
	TCase *tc_convert;

	s = suite_create("Convert");

	tc_convert = tcase_create("Core");

	tcase_add_test(tc_convert, test_convertSingleRomanNumeralCharToInt);

	tcase_add_test(tc_convert, test_convertRomanNumeralStringToInt_VI);

	suite_add_tcase(s, tc_convert);

	return s;
}