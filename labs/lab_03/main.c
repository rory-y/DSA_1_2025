#include <stdio.h>
#include "library.h"
#include "Students/student_functions.h"

int main(void)
{
  //
    //printf("%d\n", sum(1, 2));
    //printf("%d\n", testPrime(5));

  // read from keyboard
  // Student_t student1;
  // readStudentDetails (&student1);
  // printStudentDetails (student1);
/*
  // adatok értékadással -> with hard code
  Student_t student2 = {"name1 name1", "456fdg", "birth place 2", 2020,12,21,2,6.9};
  printStudentDetails (student2);

  // adatok beolvasása állományból
  printf("-----------------------\n");
  if (!freopen("students.txt", "r", stdin))
    {
      printf("Error opening file!\n");
      return -1;
    }
  Student_t student3;
  readStudentDetails (&student3);
  printStudentDetails (student3);
  freopen("CON", "w", stdout);
  printf("DONE!");
*/
  // adatok beolvasása tömbbe
  Student_t *studentArray;
  int n;
  readAllStudentsDetails (&studentArray, &n, "more_students.txt");
  printAllStudents (studentArray, n, "output.txt"); // can't set to "CON" because linux gets confused af

    return 0;
}
