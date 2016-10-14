#include <stdbool.h>
#include <string.h>
#include "infix_to_postfix.h"

bool is_variable(char value);
void char_stack_push(char *stack, int value);
char char_stack_pop(char *stack);
char char_stack_peek(char *stack);
void clear_string(char *string);

void infix_to_postfix(char *infix, char *postfix) {
  postfix[0] = '\0';

  int length = strlen(infix);
  char operators[length / 2];
  operators[0] = '\0';

  for(int i = 0; i < length; i++) {
    char value = infix[i];

    if(is_variable(value)) {
      char_stack_push(postfix, value);
    } else {
      if(char_stack_peek(operators) == '*') {
          char operator = char_stack_pop(operators);
          char_stack_push(postfix, operator);
      }

      char_stack_push(operators, value);
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

char char_stack_pop(char *stack) {
  int top = -1;
  while(stack[top + 1] != '\0') {
    top++;
  }

  char value = stack[top];
  stack[top] = '\0';
  return value;
}

char char_stack_peek(char *stack) {
  int top = -1;
  while(stack[top + 1] != '\0') {
    top++;
  }

  return stack[top];
}

void char_stack_push(char *stack, int value) {
  char append[2];
  append[0] = value;
  append[1] = '\0';
  strcat(stack, append);
}
