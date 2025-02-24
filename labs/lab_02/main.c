#include <stdio.h>
#include "functions.h"

int main(void) {
  // feladat 1.
  printf("Enter a number: ");
  int inputNumber1, output1 = 0;
  scanf("%d", &inputNumber1);

  while (inputNumber1 != 0)
    {
      int temp;
      temp = inputNumber1 % 10;
      output1 = sum(output1, temp);
      inputNumber1 = inputNumber1 / 10;

    }
  printf("The sum of the numbers is %d\n", output1);

    return 0;
}
