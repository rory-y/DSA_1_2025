//
// Created by palma on 5/8/2023.
//

#include "../headers/hash_table.h"

int
hashCode (int key)
{
  return key % CAPACITY;
}

HashItem
createHashItem (int key, int data)
{
  HashItem item = { key, data }; // TODO
  return item;
}
void
createHashArray (HashTable *pHashTable)
{
  pHashTable->items = (HashItem *)calloc (CAPACITY, sizeof (HashItem));
  if (!pHashTable->items)
    {
      printf (MEMORY_ALLOCATION_ERROR_MESSAGE);
      exit (MEMORY_ALLOCATION_ERROR_CODE);
    }
  for (int i = 0; i < CAPACITY; ++i)
    {
      {
        pHashTable->items[i] = dummyData; // TODO
      }
    }
  pHashTable->size = 0;
}

void
insert (HashTable *hashTable, int key, int data)
{
  if (hashTable->size >= CAPACITY)
    return;
  int index = hashCode (key);
  int i = 0;
  // if the stored data is dummyData, that means that the spot is not occupied
  while (hashTable->items[(index + i) % CAPACITY].key != dummyData.key)
    {
      {
        i++;
      }
    }
  hashTable->items[(index + i) % CAPACITY] = createHashItem (key, data);
  hashTable->size++;
}

void
display (HashTable hashTable)
{
  if (hashTable.size == 0)
    {
      printf ("The table is empty\n");
      return;
    }
  printf ("The hash table:\n\tpos\t:\tkey\tvalue\t->\tmod\n");
  for (int i = 0; i < CAPACITY; ++i)
    {
      if (hashTable.items[i].key != dummyData.key)
        {
          printf ("\t%i\t:\t%i\t%i\t->\t%i\n", i, hashTable.items[i].key,
                  hashTable.items[i].data, hashCode (hashTable.items[i].key));
        }
    }
}

int
size (HashTable hashTable)
{
  return hashTable.size;
}

void
deletes (HashTable *hashTable, int key)
{
  int index = hashCode (key);
  if (hashTable->items[index].key == dummyData.key)
    {
      printf ("\n This key does not exist \n");
      return;
    }
  int i = 0;
  while (hashTable->items[(index + i) % CAPACITY].key != key && i < CAPACITY)
    {
      i++;
    }
  if (i == CAPACITY)
    {
      printf ("\n This key does not exist \n");
      return;
    }
  hashTable->items[(index + i) % CAPACITY] = dummyData;
  hashTable->size--;
  printf ("\n Key (%d) has been removed \n", key);
}

int
search (HashTable hashTable, int key)
{
  int index = hashCode (key);
  if (hashTable.items[index].key == dummyData.key)
    {
      return -1;
    }
  int i = 0;
  while (hashTable.items[(index + i) % CAPACITY].key != key && i < CAPACITY)
    {
      i++;
    }
  if (i == CAPACITY)
    return -1;
  return (index + i) % CAPACITY;
}

void
destroyHashArray (HashTable *pHashTable)
{
  pHashTable->size = 0;
  free (pHashTable->items);
  pHashTable = NULL;
}
