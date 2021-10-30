#ifndef __$__tm_queue_c 
#define __$__tm_queue_c 
#include<stdio.h> 
#include<stdlib.h> 
#include<tm_required.h> 
#include<tm_singly.h> 
#include<tm_queue.h> 
Queue * createQueue(int *success) 
{ 
Queue *queue;
int xyz; 
if(success) *success=false; 
queue=(Queue *)malloc(sizeof(Queue)); 
if(queue==NULL) return NULL; 
queue->list=createSinglyLinkedList(&xyz); 
if(!xyz) 
{ 
free(queue); 
return NULL; 
} 
return queue; 
} 
void releaseQueue(Queue *queue) 
{ 
clearQueue(queue); 
releaseSinglyLinkedList(queue->list); 
free(queue); 
} 
void clearQueue(Queue *queue) 
{ 
clearSinglyLinkedList(queue->list); 
} 
void pushOnQueue(Queue *queue,void *ptr,int *success) 
{ 
if(success) *success=false; 
if(queue==NULL) return; 
insertInSinglyLinkedList(queue->list,ptr,0,success); 
} 
void * peekInQueue(Queue *queue,int *success) 
{ 
if(success)*success=false; 
if(queue==NULL) return NULL; 
return getElementFromSinglyLinkedList(queue->list,0,success); 
} 
void * popFromQueue(Queue *queue,int *success) 
{ 
if(success)*success=false; 
if(queue==NULL) return NULL; 
return removeFromSinglyLinkedList(queue->list,0,success); 
} 
int isQueueEmpty(Queue *queue) 
{ 
if(queue==NULL) return true; 
return getSizeOfSinglyLinkedList(queue->list)==0; 
} 
int getSizeOfQueue(Queue *queue) 
{
if(queue==NULL) return 0; 
return getSizeOfSinglyLinkedList(queue->list); 
} 
#endif 