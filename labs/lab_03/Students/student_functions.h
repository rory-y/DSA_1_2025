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
  char neptunCode[9]; // this has to be 1 more than the actual max character length, so 8 instead of 9
  char birthPlace[51];
  Date_t dateOfBirth;
  GENDER gender;
  float examResult;
}Student_t;

#ifndef STUDENT_FUNCTINOS_H
#define STUDENT_FUNCTINOS_H

void readStudentDetails(Student_t* pStudent);
void printStudentDetails(Student_t pStudent);

char* getGender(GENDER Gender);

/**
* Allocates memory for an array of Student_t types, array must be
passed by reference
* @param dpStudents - double pointer to a Student_t type
* @param numberOfStudents
*/
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);

/**
* Reads all students' data from an input
* This function should call first the @allocateMemoryForStudents
function
* @param dpStudents - double pointer to a Student_t type
* @param numberOfStudents
* @param input CON or input file name
*/
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input);

/**
* Prints all students to a given destination
* @param pStudents - pointer to a student, start of the array
* @param numberOfStudents
* @param destination CON or output file name
*/
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);

#endif //STUDENT_FUNCTINOS_H
