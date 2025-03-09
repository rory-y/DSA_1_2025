#include <stdio.h>
#include "library.h"
#include "Students/student_functions.h"

int main(void)
{
  //
    //printf("%d\n", sum(1, 2));
    //printf("%d\n", testPrime(5));
  Student_t student1;
  readStudentDetails (&student1);
  printStudentDetails (student1);

    return 0;
}
