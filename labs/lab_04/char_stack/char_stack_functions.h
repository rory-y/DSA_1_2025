//
// Created by rory on 3/17/25.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
        int capacity;
        int top;
        char *elements;
} CharStack_t;

#ifndef CHAR_STACK_FUNCTIONS_H
#define CHAR_STACK_FUNCTIONS_H

/**
 * Initializing the capacity and size of stack,
 * allocating memory for the @elements array
 * @param capacity
 * @param stack
 */
void createCharStack (int capacity, CharStack_t *stack);

/**
 * Deallocates the memory
 * @param stack
 */
void destroyCharStack (CharStack_t *stack);
/**
 * Checks whether the stack is full
 * @param stack
 * @return
 */
bool isFullch (CharStack_t stack);

/**
 * Checks whether the stack is empty
 * @param stack
 * @return
 */
bool isEmptych (CharStack_t stack);

/**
 * Pushes a new item to the stack,
 * if it is not full
 * @param stack
 * @param item
 */
void pushChar (CharStack_t *stack, char item);

/**
 * Removes the top element from the stack,
 * if it is not empty
 * @param stack
 * @return
 */
int popChar (CharStack_t *stack);

/**
 * Returns the top element of the stack,
 * if it is not empty
 * @param stack
 * @return
 */
int peekChar (CharStack_t stack);

/**
 * Returns the size of the stack
 * @param stack
 * @return
 */
int sizeChar (CharStack_t stack);

/**
 *
 * @param stack
 * @return
 */
bool isPalindrome (CharStack_t stack, char *input);

#endif // CHAR_STACK_FUNCTIONS_H
