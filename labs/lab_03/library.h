#include <stdbool.h>
#ifndef TESTLIB_LIBRARY_H
#define TESTLIB_LIBRARY_H

/**
 * returns the sum of two integers as an integer
 * @param a number_1 (integer)
 * @param b number_2 (integer)
 * @return (number_1 + number_2)
 */
int sum(int a, int b);

/**
* @param n number to test for prime (integer)
*/
bool testPrime(int n);

#endif //TESTLIB_LIBRARY_H