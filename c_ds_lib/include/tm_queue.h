#ifndef __$__tm_queue_h 
#define __$__tm_queue_h 4234 
#include<tm_singly.h> 
typedef struct _$_Queue 
{ 
SinglyLinkedList *list; 
}Queue; 
Queue * createQueue(int *success); 
void releaseQueue(Queue *queue); 
void clearQueue(Queue *queue); 
void pushOnQueue(Queue *queue,void *ptr,int *success); 
void * popFromQueue(Queue *queue,int *success); 
int isQueueEmpty(Queue *queue); 
void * peekInQueue(Queue *queue,int *success); 
int getSizeOfQueue(Queue *queue); 
#endif
