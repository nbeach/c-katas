#include <stdlib.h>
#include <stdbool.h>
#include <check.h>

#include "../src/infix_to_postfix.h"

START_TEST (infix_to_postfix_converts_expressions_with_only_addition)
{
  char actual[10];
  infix_to_postfix("a+b+c", actual);
  ck_assert_str_eq("ab+c+", actual);
}
END_TEST

START_TEST (infix_to_postfix_converts_expressions_with_only_subtraction)
{
  char actual[10];
  infix_to_postfix("a-b-c", actual);
  ck_assert_str_eq("ab-c-", actual);
}
END_TEST

START_TEST (infix_to_postfix_converts_expressions_with_only_multiplication)
{
  char actual[10];
  infix_to_postfix("a*b*c", actual);
  ck_assert_str_eq("ab*c*", actual);
}
END_TEST

START_TEST (infix_to_postfix_converts_expressions_with_only_division)
{
  char actual[10];
  infix_to_postfix("a/b/c", actual);
  ck_assert_str_eq("ab/c/", actual);
}
END_TEST

START_TEST (infix_to_postfix_converts_expressions_with_only_exponents)
{
  char actual[10];
  infix_to_postfix("a^b^c", actual);
  ck_assert_str_eq("ab^c^", actual);
}
END_TEST

START_TEST (infix_to_postfix_converts_expressions_with_operators_of_mixed_precedence)
{
  char actual[10];
  infix_to_postfix("a^b+c-d*e/f", actual);
  ck_assert_str_eq("ab^c+de*f/-", actual);
}
END_TEST

START_TEST (infix_to_postfix_converts_expressions_with_parenthesis)
{
  char actual[10];
  infix_to_postfix("a*(b+c)", actual);
  ck_assert_str_eq("abc+*", actual);
}
END_TEST



Suite * infix_postfix_suite() {
  Suite *s = suite_create("infix_to_postfix_test");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, infix_to_postfix_converts_expressions_with_only_addition);
  tcase_add_test(tc_core, infix_to_postfix_converts_expressions_with_only_subtraction);
  tcase_add_test(tc_core, infix_to_postfix_converts_expressions_with_only_multiplication);
  tcase_add_test(tc_core, infix_to_postfix_converts_expressions_with_only_division);
  tcase_add_test(tc_core, infix_to_postfix_converts_expressions_with_only_exponents);
  tcase_add_test(tc_core, infix_to_postfix_converts_expressions_with_operators_of_mixed_precedence);
  tcase_add_test(tc_core, infix_to_postfix_converts_expressions_with_parenthesis);

  suite_add_tcase(s, tc_core);
  return s;
}
