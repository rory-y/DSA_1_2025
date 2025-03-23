#include "char_stack/char_stack_functions.h"
#include "int_stack/int_stack_functions.h"
#include <stdio.h>

#include <string.h>

int
main (void)
{
    // doing the same excersise from week-03 team thing
    Stack_t stack;
    createStack (4, &stack);
    push (&stack, 1);
    push (&stack, 2);
    push (&stack, 3);
    push (&stack, 4);
    push (&stack, 5); // ez mar nem kerul be, mert a stack full
    printf ("Popped out: %d\n", pop (&stack));
    printf ("Popped out: %d\n", pop (&stack));
    push (&stack, 6);
    push (&stack, 7);
    push (&stack, 8);
    printf ("Popped out: %d\n", pop (&stack));
    printf ("Peeked: %d\n", peek (stack));

    // idk
    int sum = 0;
    while (!isEmpty (stack))
        {
            sum += pop (&stack);
            // pop(&stack);
        }
    printf ("the sum of the remaining elements is: %d\n", sum);

    // pallindrom ellenorzes stack-el
    // make the previous functions work with chars
    CharStack_t char_stack; // creating new stack struct
    createCharStack (4, &char_stack);
    char testMe[4] = "AbbA";
    // this part doesn't run for some reason
    printf ("test: %d\n", char_stack.capacity);
    /*for (int i = 0; i < char_stack.capacity; i++)*/
    /*    {*/
    /*        pushChar (&char_stack, testMe[i]);*/
    /*    }*/
    printf (isPalindrome (char_stack, testMe) ? "true\n" : "false\n");

    return 0;
}
