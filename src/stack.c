#include <string.h>

void char_stack_push(char *stack, int value) {
  char append[2];
  append[0] = value;
  append[1] = '\0';
  strcat(stack, append);
}

char char_stack_peek(char *stack) {
  int top = -1;
  while(stack[top + 1] != '\0') {
    top++;
  }

  return stack[top];
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
