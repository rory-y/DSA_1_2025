//
// Created by rory on 3/17/25.
//
#include "int_stack_functions.h"

#include <limits.h>
#include <stdlib.h>

void
createStack (int capacity, Stack_t *stack)
{
  stack->top = -1;
  stack->capacity = capacity;
  stack->elements = (int*) malloc(sizeof(int) * capacity);
}

void
destroyStack (Stack_t *stack)
{
  stack->top = -1;
  stack->capacity = 0;
  free(stack->elements);
  stack = NULL;
}

bool isFull(Stack_t stack)
{
  return stack.top == stack.capacity - 1;
}

bool
isEmpty (Stack_t stack)
{
  return stack.top == -1;
}

void
push (Stack_t *stack, int item)
{
  if (isFull(*stack))
    {
      printf("Stack is full. Failed to push '%d'\n", item);
      // exit(-3);
    }
  else
    {
      stack->elements[++stack->top] = item;
    }
}

int
pop (Stack_t *stack)
{
  if (isEmpty(*stack))
    {
      printf("Stack is empty\n");
      return INT_MIN;
    }
  int save = stack->elements[stack->top];
  stack->elements[stack->top--] = 0;
  return save;
}

int
peek (Stack_t stack)
{
  if (isEmpty(stack))
    {
      printf("Stack is empty\n");
      return INT_MIN;
    }
  return stack.elements[stack.top];
}

int
size (Stack_t stack)
{
  return stack.top + 1;
}