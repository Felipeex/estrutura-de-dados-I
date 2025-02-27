#include "stack.h"

int main() {
  Stack firstStack;

  start(firstStack);
  
  push(firstStack, 1);
  push(firstStack, 2);

  view(firstStack);

  return 0;
}