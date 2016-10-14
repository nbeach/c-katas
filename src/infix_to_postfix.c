#include <stdbool.h>
#include <string.h>
#include "infix_to_postfix.h"

bool is_variable(char value);
void append_char(char *dest, char value);

void infix_to_postfix(char *infix, char *postfix) {
  postfix[0] = '\0';

  int length = strlen(infix);
  char operators[length / 2];
  operators[0] = '\0';

  for(int i = 0; i < length; i++) {
    char value = infix[i];

    if(is_variable(value)) {
      append_char(postfix, value);
    } else {
      append_char(operators, value);
    }
  }

  strcat(postfix, operators);
}

bool is_variable(char value) {
  return value >= 'a' && value <= 'z';
}

void append_char(char *dest, char value) {
  char append[2];
  append[0] = value;
  append[1] = '\0';
  strcat(dest, append);
}
