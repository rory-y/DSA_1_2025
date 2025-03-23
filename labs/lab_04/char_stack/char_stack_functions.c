//
// Created by rory on 3/17/25.
//
#include "char_stack_functions.h"

#include <limits.h>
#include <stdlib.h>

void
createCharStack (int capacity, CharStack_t *stack)
{
    stack->top = -1;
    stack->capacity = capacity;
    stack->elements = (char *)malloc (sizeof (char) * capacity);
}

void
destroyCharStack (CharStack_t *stack)
{
    stack->top = -1;
    stack->capacity = 0;
    free (stack->elements);
    stack = NULL;
}

bool
isFullch (CharStack_t stack)
{
    return stack.top == stack.capacity - 1;
}

bool
isEmptych (CharStack_t stack)
{
    return stack.top == -1;
}

void
pushChar (CharStack_t *stack, char item)
{
    if (isFullch (*stack))
        {
            printf ("Stack is full. Failed to push '%c'\n", item);
            // exit(-3);
        }
    else
        {
            stack->elements[++stack->top] = item;
        }
}

int
popChar (CharStack_t *stack)
{
    if (isEmptych (*stack))
        {
            printf ("Stack is empty\n");
            return INT_MIN;
        }
    int save = stack->elements[stack->top];
    stack->elements[stack->top--] = 0;
    return save;
}

int
peekChar (CharStack_t stack)
{
    if (isEmptych (stack))
        {
            printf ("Stack is empty\n");
            return CHAR_MIN;
        }
    return stack.elements[stack.top];
}

int
sizeChar (CharStack_t stack)
{
    return stack.top + 1;
}

bool
isPalindrome (CharStack_t stack, char *input)
{
    for (int i = 0; i < stack.capacity; i++)
        {
            pushChar (&stack, input[i]);
        }

    for (int i = 0; i < stack.capacity; i++)
        {
            if (input[i] != popChar (&stack))
                {
                    return false;
                }
        }

    return true;
}
