#include "glasses_circular_queue.h"

#include <stdio.h>

int
main (void)
{
  CircularQueue_t glasses;
  createQueue (10, &glasses);

  GLASS glass;
  enqueue(&glasses, &glass);
  enqueue(&glasses, &glass);
  display(glasses);
  dequeue (&glasses);
  display(glasses);
  printf("red glasses:\n");
    displayRedGlasses (glasses);
    return 0;
}
