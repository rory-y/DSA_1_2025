#ifndef BOOK_H
#define BOOK_H

#include "main.h"


typedef struct
{
  int year;
  int month;
  int day;
}Date_t;

typedef struct
{
  char title[30];
  char author[30];
  Date_t publicationDate;
  bool inLibrary; // kölcsönzési státusz -> tree insert after this
}Book_t;

/* READ FUNCTIONS */

// simple read one book from file
/**
 *
 * @param inputStream
 * @return
 */
Book_t readOneBookFromFile(FILE *inputStream);

/* PRINT FUNCTIONS */

// simple print one date
/**
 * 
 * @param input 
 */
void printDate(Date_t input);

// simple print one book
/**
 * 
 * @param input 
 */
void printBook(Book_t input);
#endif //BOOK_H
