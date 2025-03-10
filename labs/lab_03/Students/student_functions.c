#include <stdio.h>
#include "student_functions.h"
//
// Created by rory on 3/3/25.
//
void readStudentDetails(Student_t *pStudent)
{
  scanf("%[^\n]\n", pStudent->name);
  scanf("%s\n", pStudent->neptunCode);
  scanf("%[^\n]\n", pStudent->birthPlace);
  scanf("%d%d%d\n", &pStudent->dateOfBirth.year, &pStudent->dateOfBirth.month, &pStudent->dateOfBirth.day);
  scanf("%d", &pStudent->gender);
  scanf("%f", &pStudent->examResult);
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
    case 0:
      printf("NON BINARY\n");
      break;
    case 1:
      printf("MALE\n");
      break;
    case 2:
      printf("FEMALE\n");
      break;
    default:
      break;
    }
  printf("%.2f\n", pStudent.examResult);
}

