#include <stdio.h>
#include <fcntl.h>
#include "functions.h"

#include <stdlib.h>


int main(void)
{
  // feladat 1.
  // osszeadja a szam szamjegyeit
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

  // feladat 2.
  // tomb elso kozepso utolso szamai kozul a legkissebbet
  // csak paratlan elemu tombre mukodik
  int inputNumber2;
  // printf("Enter an odd number (array elements): ");
  // scanf("%d", &inputNumber2);
  bool check = 1;
  while (check)
    {
      if (inputNumber2 % 2 != 0)
        {
          check = 0; // breaks out of the loop on the next execution
        }
      else
        {
          printf("Enter an odd number (array elements): ");
          scanf("%d", &inputNumber2);
        }
    }
  float* array2;
  allocateMemoryForFloatArray2(inputNumber2, &array2);
  fillWithRandomFloats (inputNumber2, array2, 0, 1);
  printFloatArray(inputNumber2, array2, "output2.txt");

  float output2 = 0;
  output2 = min(array2[0], array2[(inputNumber2/2) + 1], array2[inputNumber2 - 1]);
  printf("%f\n", output2);
  printf("The minimum number is %f\n", output2);

  deallocateMemoryForFloatArray(&array2);

  // feladat 3.
  // Mátrix adott oszlopából a legkisebb
  int rows, cols;
  FILE * file3 = fopen("matrix.txt", "r");
  if (file3 == NULL)
    {
      perror("Error opening file");
      exit(1);
    }
  fscanf(file3, "%d %d", &rows, &cols);
  char** tpArray;
  allocateMemoryFor2DCharArray2 (rows, cols, &tpArray);
  read2DCharArray (&rows, &cols, &tpArray, "matrix.txt");
  print2DCharArray (rows, cols, tpArray);

  fclose (file3);
  deallocateMemoryFor2DCharArray (rows, &tpArray);

    return 0;
}
