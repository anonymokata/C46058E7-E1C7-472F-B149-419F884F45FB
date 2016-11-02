#include "check_convert.h"
#include <check.h>

START_TEST(test_convertSingleRomanNumeralCharToInt)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("I"), 1);
}
END_TEST

START_TEST(test_convertRomanNumeralStringToInt_VI)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("VI"), 6);
}
END_TEST

START_TEST(test_convertRomanNumeralStringToInt_Recognizes_BadCharInString_MJ)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("MJ"), -1);
}
END_TEST

START_TEST(test_convertRomanNumeralStringToInt_Recognizes_BadCharInString_JM)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("JM"), -1);
}
END_TEST

START_TEST(test_subtractIfNextCharIsSmallerThanCurrentChar_IX)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("IX"), 9);
}
END_TEST

START_TEST(test_convertRomanNumeralString_detectBadSubtractionPair_IC)
{
	ck_assert_int_eq(convertRomanNumeralStringToInt("IC"), -1);
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

	tcase_add_test(tc_convert, test_convertRomanNumeralStringToInt_Recognizes_BadCharInString_MJ);
	tcase_add_test(tc_convert, test_convertRomanNumeralStringToInt_Recognizes_BadCharInString_JM);

	tcase_add_test(tc_convert, test_subtractIfNextCharIsSmallerThanCurrentChar_IX);

	tcase_add_test(tc_convert, test_convertRomanNumeralString_detectBadSubtractionPair_IC);

	suite_add_tcase(s, tc_convert);

	return s;
}
