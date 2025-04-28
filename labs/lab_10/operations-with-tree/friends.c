#include "friends.h"
#include <stdio.h>
void printFriend(Friend friend) {
  printf("Name: %s\n", friend.nev);
  printf("\tbirth date: %d-%d-%d\n", friend.szuletesiDatum.ev,
         friend.szuletesiDatum.honap, friend.szuletesiDatum.nap);
  printf("\tgender: %c\n", friend.nem);
  printf("\tparty rating: %d", friend.bulizas);
}
