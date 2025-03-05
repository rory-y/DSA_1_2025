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
  printf("")
}

