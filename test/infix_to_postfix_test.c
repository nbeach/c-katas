#include <stdlib.h>
#include <stdbool.h>
#include <check.h>

#include "../src/infix_to_postfix.h"

START_TEST (infix_to_postfix_converts_expressions_with_only_addition_of_variables)
{
  char actual[10];
  infix_to_postfix("a+b+c", actual);
  ck_assert_str_eq("abc++", actual);
}
END_TEST

Suite * infix_postfix_suite() {
  Suite *s = suite_create("infix_to_postfix_test");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, infix_to_postfix_converts_expressions_with_only_addition_of_variables);

  suite_add_tcase(s, tc_core);
  return s;
}
