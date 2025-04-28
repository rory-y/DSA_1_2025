#include "main.h"

int main(void) {
  freopen("data.txt", "r", stdin);
  Friend uj;
  Node *head = NULL;
  while ((scanf("%[^;];%d;%d;%d;%c;%d\n", uj.nev, &uj.szuletesiDatum.ev,
                &uj.szuletesiDatum.honap, &uj.szuletesiDatum.nap, &uj.nem,
                &uj.bulizas) != EOF)) {
    if (head == NULL) {
      head = createNewNode(uj);
    }
  }
}
