#ifndef __$__tm_doubly_c 
#define __$__tm_doubly_c 234 
#include<stdio.h> 
#include<tm_required.h> 
#include<tm_doubly.h> 
#include<stdlib.h> 
DoublyLinkedList * createDoublyLinkedList(int *success) 
{ 
DoublyLinkedList *dll; 
if(success) *success=false; 
dll=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList)); 
if(dll==NULL) return NULL; 
if(success) *success=true; 
dll->start=NULL; 
dll->end=NULL; 
dll->count=0; 
return dll; 
} 
void addToDoublyLinkedList(DoublyLinkedList *dll,void *ptr,int *success) 
{ 
struct _$_DLL_Node *t; 
if(success) *success=false; 
if(dll==NULL) return; 
t=(struct _$_DLL_Node *)malloc(sizeof(struct _$_DLL_Node)); 
if(t==NULL) return; 
t->ptr=ptr; 
t->next=NULL; 
t->previous=NULL;
if(dll->start==NULL) 
{ 
dll->start=dll->end=t; 
} 
else 
{ 
dll->end->next=t; 
t->previous=dll->end; 
dll->end=t; 
} 
dll->count++; 
if(success) *success=true; 
} 
void * getElementFromDoublyLinkedList(DoublyLinkedList *dll,int index,int *success) 
{ 
int x; 
struct _$_DLL_Node *t; 
void *ptr=NULL; 
if(success) *success=false; 
if(dll==NULL) return NULL; 
if(index<0 || index>=dll->count) return NULL; 
for(x=0,t=dll->start;x<index;x++,t=t->next); 
ptr=t->ptr; 
if(success) *success=true; 
return ptr; 
} 
void releaseDoublyLinkedList(DoublyLinkedList *dll) 
{ 
clearDoublyLinkedList(dll); 
free(dll); 
} 
DoublyLinkedListIterator * getDoublyLinkedListIterator(DoublyLinkedList *dll,int direction) 
{ 
DoublyLinkedListIterator *iterator; 
if(dll==NULL) return NULL; 
if(direction!=1 && direction!=2) return NULL; 
iterator=(DoublyLinkedListIterator *)malloc(sizeof(DoublyLinkedListIterator)); 
iterator->direction=direction; 
if(direction==1) 
{ 
iterator->node=dll->start; 
} 
else  // direction is 2 
{ 
iterator->node=dll->end; 
} 
return iterator;
} 
int hasMoreElementsInDoublyLinkedList(DoublyLinkedListIterator *iterator) 
{ 
if(iterator==NULL) return false; 
return iterator->node!=NULL; 
} 
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *iterator,int *success) 
{ 
void *ptr; 
if(success) *success=false; 
if(iterator==NULL) return NULL; 
if(iterator->node==NULL)  return NULL; 
ptr=iterator->node->ptr; 
if(iterator->direction==1) 
{ 
iterator->node=iterator->node->next; 
} 
else 
{ 
iterator->node=iterator->node->previous; 
} 
return ptr; 
} 
void releaseDoublyLinkedListIterator(DoublyLinkedListIterator *iterator) 
{ 
if(iterator==NULL) return; 
free(iterator); 
} 
void insertInDoublyLinkedList(DoublyLinkedList *dll,void *ptr,int index,int *success) 
{ 
struct _$_DLL_Node *t,*p1; 
int x; 
if(success) *success=false; 
if(dll==NULL) return; 
if(index<0 || index>dll->count) return; 
t=(struct _$_DLL_Node *)malloc(sizeof(struct _$_DLL_Node)); 
if(t==NULL) return; 
t->ptr=ptr; 
t->next=NULL; 
t->previous=NULL; 
for(x=0,p1=dll->start;x<index;x++,p1=p1->next); 
if(p1==NULL) 
{ 
if(dll->start==NULL) 
{ 
dll->start=dll->end=t; 
}
else 
{ 
dll->end->next=t; 
t->previous=dll->end; 
dll->end=t; 
} 
dll->count++; 
if(success) *success=true; 
return; 
} 
if(p1==dll->start) 
{ 
t->next=dll->start; 
dll->start->previous=t; 
dll->start=t; 
dll->count++; 
if(success) *success=true; 
return; 
} 
t->next=p1; 
t->previous=p1->previous; 
p1->previous->next=t; 
p1->previous=t; 
dll->count++; 
if(success) *success=true; 
} 
void * removeFromDoublyLinkedList(DoublyLinkedList *dll,int index,int *success) 
{ 
void *ptr; 
int x; 
struct _$_DLL_Node *p1; 
if(success) *success=false; 
if(dll==NULL) return NULL; 
if(index<0 || index>=dll->count) return NULL; 
x=0; 
p1=dll->start; 
while(x<index) 
{ 
p1=p1->next; 
x++; 
} 
ptr=p1->ptr; 
if(p1==dll->start && p1==dll->end) 
{ 
dll->start=dll->end=NULL; 
} 
else if(p1==dll->start)
{ 
dll->start=dll->start->next; 
dll->start->previous=NULL; 
} 
else if(p1==dll->end) 
{ 
dll->end=dll->end->previous; 
dll->end->next=NULL; 
} 
else 
{ 
p1->previous->next=p1->next; 
p1->next->previous=p1->previous; 
} 
free(p1); 
dll->count--; 
if(success) *success=true; 
return ptr; 
} 
void clearDoublyLinkedList(DoublyLinkedList *dll) 
{ 
struct _$_DLL_Node *t; 
if(dll==NULL) return; 
while(dll->start!=NULL) 
{ 
t=dll->start; 
dll->start=dll->start->next; 
free(t); 
} 
dll->end=NULL; 
dll->count=0; 
} 
int getSizeOfDoublyLinkedList(DoublyLinkedList *dll) 
{ 
if(dll==NULL) return 0; 
return dll->count; 
} 
#endif 
