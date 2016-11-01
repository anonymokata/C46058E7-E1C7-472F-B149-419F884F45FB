/*
 * check_romanNumeralCalc.c
 *
 *  Created on: Oct 24, 2016
 *      Author: brad
 */
#include <stdlib.h>
#include "check_convert.h"
#include <check.h>

int main(void)
{
	int numberOfTestsFailed;
	Suite *s;
	SRunner *sr;

	s = convert_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	numberOfTestsFailed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (numberOfTestsFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
