#ifndef __$__tm_singly_c 
#define __$__tm_singly_c 234 
#include<stdio.h> 
#include<tm_required.h> 
#include<tm_singly.h> 
#include<stdlib.h> 
SinglyLinkedList * createSinglyLinkedList(int *success) 
{ 
SinglyLinkedList *sll; 
if(success) *success=false; 
sll=(SinglyLinkedList *)malloc(sizeof(SinglyLinkedList)); 
if(sll==NULL) return NULL; 
if(success) *success=true; 
sll->start=NULL; 
sll->end=NULL; 
sll->count=0; 
return sll; 
} 
void addToSinglyLinkedList(SinglyLinkedList *sll,void *ptr,int *success) 
{ 
struct _$_SLL_Node *t; 
if(success) *success=false; 
if(sll==NULL) return; 
t=(struct _$_SLL_Node *)malloc(sizeof(struct _$_SLL_Node)); 
if(t==NULL) return; 
t->ptr=ptr; 
t->next=NULL; 
if(sll->start==NULL) 
{ 
sll->start=sll->end=t; 
} 
else 
{ 
sll->end->next=t; 
sll->end=t; 
} 
sll->count++; 
if(success) *success=true; 
} 
void * getElementFromSinglyLinkedList(SinglyLinkedList *sll,int index,int *success)
{ 
int x; 
struct _$_SLL_Node *t; 
void *ptr=NULL; 
if(success) *success=false; 
if(sll==NULL) return NULL; 
if(index<0 || index>=sll->count) return NULL; 
for(x=0,t=sll->start;x<index;x++,t=t->next); 
ptr=t->ptr; 
if(success) *success=true; 
return ptr; 
} 
void releaseSinglyLinkedList(SinglyLinkedList *sll) 
{ 
struct _$_SLL_Node *t; 
if(sll==NULL) return; 
while(sll->start!=NULL) 
{ 
t=sll->start; 
sll->start=sll->start->next; 
free(t); 
} 
free(sll); 
}
SinglyLinkedListIterator * getSinglyLinkedListIterator(SinglyLinkedList *sll) 
{ 
SinglyLinkedListIterator *iterator; 
if(sll==NULL) return NULL; 
iterator=(SinglyLinkedListIterator *)malloc(sizeof(SinglyLinkedListIterator)); 
iterator->node=sll->start; 
return iterator; 
}
int hasMoreElementsInSinglyLinkedList(SinglyLinkedListIterator *iterator) 
{ 
if(iterator==NULL) return false; 
return iterator->node!=NULL; 
} 
void * getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *iterator,int *success) 
{ 
void *ptr; 
if(success) *success=false; 
if(iterator==NULL) return NULL; 
if(iterator->node==NULL)  return NULL; 
ptr=iterator->node->ptr; 
iterator->node=iterator->node->next; 
return ptr; 
} 
void releaseSinglyLinkedListIterator(SinglyLinkedListIterator *iterator) 
{ 
if(iterator==NULL) return; 
free(iterator); 
}
void insertInSinglyLinkedList(SinglyLinkedList *sll,void *ptr,int index,int *success) 
{ 
struct _$_SLL_Node *t,*p1,*p2;
int x; 
if(success) *success=false; 
if(sll==NULL) return; 
if(index<0 || index>sll->count) return; 
t=(struct _$_SLL_Node *)malloc(sizeof(struct _$_SLL_Node)); 
if(t==NULL) return; 
t->ptr=ptr; 
t->next=NULL; 
for(x=0,p1=sll->start;x<index;x++,p1=p1->next) p2=p1; 
if(p1==NULL) 
{ 
if(sll->start==NULL) 
{ 
sll->start=sll->end=t; 
} 
else 
{ 
sll->end->next=t; 
sll->end=t; 
} 
sll->count++; 
if(success) *success=true; 
return; 
} 
if(p1==sll->start) 
{ 
t->next=sll->start; 
sll->start=t; 
sll->count++; 
if(success) *success=true; 
return; 
} 
t->next=p1; 
p2->next=t; 
sll->count++; 
if(success) *success=true; 
} 
void * removeFromSinglyLinkedList(SinglyLinkedList *sll,int index,int *success) 
{ 
void *ptr; 
int x; 
struct _$_SLL_Node *p1,*p2; 
if(success) *success=false; 
if(sll==NULL) return NULL; 
if(index<0 || index>=sll->count) return NULL; 
x=0; 
p1=sll->start;
while(x<index) 
{ 
p2=p1; 
p1=p1->next; 
x++; 
} 
ptr=p1->ptr; 
if(p1==sll->start && p1==sll->end) 
{ 
sll->start=sll->end=NULL; 
} 
else if(p1==sll->start) 
{ 
sll->start=sll->start->next; 
} 
else if(p1==sll->end) 
{ 
sll->end=p2; 
sll->end->next=NULL; 
} 
else 
{ 
p2->next=p1->next; 
} 
free(p1); 
sll->count--; 
if(success) *success=true; 
return ptr; 
} 
void clearSinglyLinkedList(SinglyLinkedList *sll) 
{ 
struct _$_SLL_Node *t; 
if(sll==NULL) return; 
while(sll->start!=NULL) 
{ 
t=sll->start; 
sll->start=sll->start->next; 
free(t); 
} 
sll->end=NULL; 
sll->count=0; 
} 
int getSizeOfSinglyLinkedList(SinglyLinkedList *sll) 
{ 
if(sll==NULL) return 0; 
return sll->count; 
}
#endif