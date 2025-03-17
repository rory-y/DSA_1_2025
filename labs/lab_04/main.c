#include <stdio.h>
#include "int_stack/int_stack_functions.h"
#include "char_stack/char_stack_functions.h"

#include <string.h>

int main(void) {
  // doing the same excersise from week-03 team thing
  Stack_t stack;
    createStack(4, &stack);
      push(&stack, 1);
      push(&stack, 2);
      push(&stack, 3);
      push(&stack, 4);
      push(&stack, 5); // ez mar nem kerul be, mert a stack full
  printf("Popped out: %d\n", pop(&stack));
  printf("Popped out: %d\n", pop(&stack));
      push(&stack, 6);
      push(&stack, 7);
      push(&stack, 8);
  printf("Popped out: %d\n", pop(&stack));
  printf("Peeked: %d", peek(stack));

  // idk
  int sum = 0;
  while (!isEmpty(stack))
    {
      sum += pop(&stack);
      // pop(&stack);
    }
  printf("the sum of the remaining elements is: %d", sum);

  // pallindrom ellenorzes stack-el
  // make the previous functions work with chars
  CharStack_t char_stack;
  createCharStack(4, &char_stack);
  for (int i = 0; i < strlen(char_stack.elements); i++)
    {
      char chInput;
      scanf("%s", &chInput);
      pushChar(&char_stack, chInput);
    }


    return 0;
}
