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
} Friend;

/**
 *
 * @param friend friend to print to the current stream
 */
void printFriend (Friend f);
