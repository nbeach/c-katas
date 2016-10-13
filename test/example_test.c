#include <stdlib.h>
#include <stdbool.h>
#include <check.h>

START_TEST (trueIsTrue)
{
  bool actual = true;
  ck_assert_int_eq(actual, true);
}
END_TEST

Suite * example_suite() {
  Suite *s = suite_create("Example");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, trueIsTrue);

  suite_add_tcase(s, tc_core);
  return s;
}
