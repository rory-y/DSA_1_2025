typedef struct Datum
{
  int ev;
  int honap;
  int nap;
} Datum;

typedef struct Friend
{
  char nev[100];
  Datum szuletesiDatum;
  char nem;
  int bulizas;
  struct Friend *kovetkezo;
} Friend;

typedef struct Node
{
  Friend info;
  struct Node *right;
  struct Node *left;
} Node;

/**
 *
 * @param friend friend to print to the current stream
 */
void printFriend (Friend f);
