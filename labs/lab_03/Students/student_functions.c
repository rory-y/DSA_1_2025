#include <stdio.h>
#include "student_functions.h"
//
// Created by rory on 3/3/25.
//
void readStudentDetails(Student_t *pStudent)
{
  scanf("%[^\n]\n]", pStudent->name);
  scanf("%s\n", pStudent->neptunCode);
  scanf("%^[\n]\n", pStudent->birthPlace);
  scanf("%d %d %d", pStudent->dateOfBirth.year, pStudent->dateOfBirth.month, pStudent->dateOfBirth.day);
  scanf("%d", pStudent->gender);
  scanf("%f", pStudent->examResult);
}

void
printStudentDetails (Student_t pStudent)
{
  printf("%s\n", pStudent.name);
  printf("%s\n", pStudent.neptunCode);
  printf("%s\n", pStudent.birthPlace);
  printf("%d/%d/%d\n", pStudent.dateOfBirth.year, pStudent.dateOfBirth.month,pStudent.dateOfBirth.day);
  switch (pStudent.gender)
    {
    case '0':
      printf("NON BINARY");
      break;
    case '1':
      printf("MALE");
      break;
    case '2':
      printf("FEMALE");
      break;
    default:
    }
  printf("%.2f\n", pStudent.examResult);
}

