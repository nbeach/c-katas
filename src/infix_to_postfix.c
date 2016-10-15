#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "infix_to_postfix.h"

bool is_variable(char value);
void clear_string(char *string);

void infix_to_postfix(char *infix, char *postfix) {
  postfix[0] = '\0';

  int length = strlen(infix);
  char operators[length / 2];
  operators[0] = '\0';

  for(int i = 0; i < length; i++) {
    char symbol = infix[i];

    if(is_variable(symbol)) {
      char_stack_push(postfix, symbol);
    } else {
      char stack_top = char_stack_peek(operators);
      if(stack_top == '*' || stack_top == '/') {
          char operator = char_stack_pop(operators);
          char_stack_push(postfix, operator);
      }

      char_stack_push(operators, symbol);
    }
  }

  strcat(postfix, operators);
}

bool is_variable(char value) {
  return value >= 'a' && value <= 'z';
}

void clear_string(char *string) {
  string[0] = '\0';
}
