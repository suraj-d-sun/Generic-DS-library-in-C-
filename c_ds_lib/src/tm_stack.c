#ifndef __$__tm_stack_c 
#define __$__tm_stack_c 
#include<stdio.h> 
#include<stdlib.h> 
#include<tm_required.h> 
#include<tm_singly.h> 
#include<tm_stack.h> 
Stack * createStack(int *success) 
{ 
Stack *stack;
int xyz; 
if(success) *success=false; 
stack=(Stack *)malloc(sizeof(Stack)); 
if(stack==NULL) return NULL; 
stack->list=createSinglyLinkedList(&xyz); 
if(!xyz) 
{ 
free(stack); 
return NULL; 
} 
return stack; 
} 
void releaseStack(Stack *stack) 
{ 
clearStack(stack); 
releaseSinglyLinkedList(stack->list); 
free(stack); 
} 
void clearStack(Stack *stack) 
{ 
clearSinglyLinkedList(stack->list); 
} 
void pushOnStack(Stack *stack,void *ptr,int *success) 
{ 
if(success) *success=false; 
if(stack==NULL) return; 
insertInSinglyLinkedList(stack->list,ptr,0,success); 
} 
void * peekInStack(Stack *stack,int *success) 
{ 
if(success)*success=false; 
if(stack==NULL) return NULL; 
return getElementFromSinglyLinkedList(stack->list,0,success); 
} 
void * popFromStack(Stack *stack,int *success) 
{ 
if(success)*success=false; 
if(stack==NULL) return NULL; 
return removeFromSinglyLinkedList(stack->list,0,success); 
} 
int isStackEmpty(Stack *stack) 
{ 
if(stack==NULL) return true; 
return getSizeOfSinglyLinkedList(stack->list)==0; 
} 
int getSizeOfStack(Stack *stack) 
{
if(stack==NULL) return 0; 
return getSizeOfSinglyLinkedList(stack->list); 
} 
#endif 
