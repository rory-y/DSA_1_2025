//
// Created by rory on 3/3/25.
//

typedef enum
{
  NON_BINARY,
  MALE,
  FEMALE
} GENDER;

typedef struct
{
  int year;
  int month;
  int day;
}Date_t;

typedef struct
{
  char name[51];
  char neptunCode[6];
  char birthPlace[51];
  Date_t dateOfBirth;
  GENDER gender;
  float examResult;
}Student_t;

#ifndef STUDENT_FUNCTINOS_H
#define STUDENT_FUNCTINOS_H

void readStudentDetails(Student_t* pStudent);
void printStudentDetails(Student_t pStudent);

#endif //STUDENT_FUNCTINOS_H
