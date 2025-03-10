#include <stdio.h>
#include "student_functions.h"

#include <stdlib.h>
//
// Created by rory on 3/3/25.
//
void readStudentDetails(Student_t *pStudent)
{
  scanf("%[^\n]\n", pStudent->name);
  scanf("%s\n", pStudent->neptunCode);
  scanf("%[^\n]\n", pStudent->birthPlace);
  scanf("%d%d%d\n", &pStudent->dateOfBirth.year, &pStudent->dateOfBirth.month, &pStudent->dateOfBirth.day);
  scanf("%d\n", &pStudent->gender);
  scanf("%f\n", &pStudent->examResult);
}

void
printStudentDetails (Student_t pStudent)
{
  printf("%s\n", pStudent.name);
  printf("%s\n", pStudent.neptunCode);
  printf("%s\n", pStudent.birthPlace);
  printf("%d/%d/%d\n", pStudent.dateOfBirth.year, pStudent.dateOfBirth.month,pStudent.dateOfBirth.day);
  printf("%s\n", getGender(pStudent.gender));
  printf("%.2f\n\n", pStudent.examResult);
}

char*
getGender(GENDER Gender)
{
  switch (Gender)
    {
      case 0: return "NON BINARY"; break;
      case 1: return "MALE"; break;
      case 2: return "FEMALE"; break;
      default: return "UNKNOWN"; break;
    }
}

void
allocateMemoryForStudents (Student_t **dpStudents, int numberOfStudents)
{
  *dpStudents=(Student_t*)malloc(numberOfStudents * sizeof(Student_t));
  if (!*dpStudents)
    {
      printf("Not enough memory to allocate students.\n");
      exit(-1);
    }
}

void
readAllStudentsDetails (Student_t **dpStudents, int *numberOfStudents, const char *input)
{
  if (!freopen(input, "r", stdin))
    {
      printf("Error opeing input file\n");
      exit(-2);
    }
  scanf("%d\n", numberOfStudents);
  allocateMemoryForStudents(dpStudents, *numberOfStudents);
  for (int i = 0; i < *numberOfStudents; i++)
    {
      readStudentDetails(&(*dpStudents)[i]);
    }
  freopen("CON", "r", stdin);
}

void
printAllStudents (Student_t *pStudents, int numberOfStudents, const char *destination)
{
  if (!freopen(destination, "w", stdout))
  {
    printf("Error opening output file\n");
      exit(-2);
  }
  for (int i = 0; i < numberOfStudents; i++)
    {
      printStudentDetails(pStudents[i]);
    }
  freopen("CON", "w", stdout);
}