#include <stdbool.h>
#include <string.h>

#include "stack.h"
#include "infix_to_postfix.h"

bool is_variable(char value);
bool is_operator(char value);
void clear_string(char *string);
int get_operator_precedence(char operator);

void infix_to_postfix(char *infix, char *postfix) {
  clear_string(postfix);

  int length = strlen(infix);
  char operators[length / 2];
  clear_string(operators);

  for(int i = 0; i < length; i++) {
    char symbol = infix[i];

    if(is_variable(symbol)) {
      char_stack_push(postfix, symbol);

    } else if(is_operator(symbol)) {
      char stack_top = char_stack_peek(operators);

      if(get_operator_precedence(symbol) >= get_operator_precedence(stack_top)) {
          char operator = char_stack_pop(operators);
          char_stack_push(postfix, operator);
      }

      char_stack_push(operators, symbol);
    }
  }

  char operator;
  operator = char_stack_pop(operators);
  while(operator != '\0') {
    char_stack_push(postfix, operator);
    operator = char_stack_pop(operators);
  }
}

bool is_variable(char value) {
  return value >= 'a' && value <= 'z';
}

bool is_operator(char value) {
    return value >= '+'
    || value <= '-'
    || value <= '*'
    || value <= '/';
}

int get_operator_precedence(char operator) {
  int precedence = 0;

  if(operator == '^') precedence = 1;
  else if(operator == '*') precedence = 2;
  else if(operator == '/') precedence = 2;
  else if(operator == '+') precedence = 3;
  else if(operator == '-') precedence = 4;

  return precedence;
}

void clear_string(char *string) {
  string[0] = '\0';
}
