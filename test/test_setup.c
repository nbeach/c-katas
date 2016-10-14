#include <check.h>
#include "infix_to_postfix_test.c"

int run_suites(Suite* suites[], int count);

int main() {
  int suites = 1;
  Suite* s[suites];
  s[0] = infix_postfix_suite();

  int faliures = run_suites(s, suites);
  return (faliures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int run_suites(Suite* suites[], int count) {
  int number_failed = 0;
  for(int i = 0; i < count; i ++) {
    SRunner *sr = srunner_create(suites[i]);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = number_failed + srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  return number_failed;
}
