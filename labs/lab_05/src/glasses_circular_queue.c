#include "glasses_circular_queue.h"

#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void createQueue(const int capacity, CircularQueue_t *queue) {
    queue->capacity = capacity;
    queue->glasses = (GLASS*)malloc(capacity*sizeof(GLASS));
    if (!queue->glasses) {perror("Memory allocation error!"); exit(-1);}
    queue->front = queue->rear = -1;
}
void destroyQueue(CircularQueue_t *queue) {
    free(queue->glasses);
    queue->glasses = NULL;
    queue->capacity = 0;
    queue->front = queue->rear = -1;
}
bool isFull(const CircularQueue_t queue){
    return (queue.front == (queue.rear + 1) % queue.capacity);
 }
bool isEmpty(const CircularQueue_t queue) {
    return (queue.front == -1);
}
void enqueue(CircularQueue_t *queue, GLASS *glass) {
    if (isFull(*queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    readOneGlass(glass);
    queue->glasses[queue->rear] = *glass;
}
GLASS dequeue(CircularQueue_t *queue) {
    if (isEmpty(*queue)) {
        printf("Queue is empty!\n");
        return glass0;
    }
    GLASS temp = queue->glasses[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return temp;
}
void readOneGlass(GLASS *glass) {
  scanf("\n%[^\n]",glass->color);
  scanf("%f",&glass->volume);
  scanf("%d",&glass->type);
}
char *getDescriptionType(const enum Type type) {
  switch (type) {
    case 0: return "GLASS";
    case 1: return "PLASTIC";
    default: return "OTHER";
  }
}
void printOneGlass(GLASS glass) {
  printf("%s %.2f %s\n",glass.color,glass.volume,getDescriptionType(glass.type));
}
void display(const CircularQueue_t queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = queue.front;
    while (true) {
        // printf("%d ", queue.glasses[i]);
        printOneGlass(queue.glasses[i]);
        if (i == queue.rear) break;
        i = (i + 1) % queue.capacity;
    }
    printf("\n");
}
GLASS peek(const CircularQueue_t queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return glass0;
    }
    return queue.glasses[queue.front];
}

