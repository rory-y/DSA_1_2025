#include "../headers/book.h"
#include "../headers/main.h"

Book_t
readOneBookFromFile (FILE *inputStream)
{
  Book_t output;
  fscanf(inputStream, "%[^\n]\n", output.title);
  fscanf(inputStream, "%[^\n]\n", output.author);

  Date_t tempDate;
  int tempYear = 0, tempMonth = 0, tempDay = 0;
  fscanf(inputStream, "%d\n", &tempYear);
  tempDate.year = tempYear;
  tempDate.month = tempMonth;
  tempDate.day = tempDay;
  output.publicationDate = tempDate;

  int temp = 0;
  fscanf(inputStream, "%d", &temp);
  output.inLibrary = temp;

  return output;
}

void printDate(Date_t input) {
  printf("%d/%d/%d\n", input.year, input.month, input.day);
}

void printBook(Book_t input) {
  printf("-------------------\n");
  printf("title: %s\n", input.title);
  printf("author: %s\n", input.author);
  printDate(input.publicationDate);
  printf(input.inLibrary ? "Book is in the library.\n" :
    "Book is not int the library.\n");
}
