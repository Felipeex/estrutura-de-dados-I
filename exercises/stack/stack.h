#include <stdio.h>

#define MAX_STACK 20
#define EMPTY_NUMBER -1

struct Stack {
  int top;
  int self[MAX_STACK];
};

void start(Stack stack) {
  stack.top = EMPTY_NUMBER;
}

void push(Stack &stack, int element) {
  stack.self[++stack.top] = element;
}

int pop(Stack &stack) {
  return stack.self[stack.top--];
}

int isEmpty(Stack stack) {
  return stack.top == EMPTY_NUMBER;
}

int isFull(Stack stack) {
  return stack.top >= MAX_STACK - 1;
}

void view(Stack stack) {
  while(!isEmpty(stack))
    printf("%d ", pop(stack));
}