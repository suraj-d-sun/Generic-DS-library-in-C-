#ifndef __tm__$_tm_singly_h 
#define __tm__$_tm_singly_h 234 
struct _$_SLL_Node 
{ 
void *ptr; 
struct _$_SLL_Node *next; 
}; 
typedef struct _$_SinglyLinkedList 
{ 
struct _$_SLL_Node *start; 
struct _$_SLL_Node *end; 
int count; 
}SinglyLinkedList; 
typedef struct __$_SinglyLinkedListIterator 
{ 
struct _$_SLL_Node *node; 
}SinglyLinkedListIterator; 
SinglyLinkedList * createSinglyLinkedList(int *success); 
void addToSinglyLinkedList(SinglyLinkedList *sll,void *ptr,int *success); 
void insertInSinglyLinkedList(SinglyLinkedList *sll,void *ptr,int index,int *success); 
void * removeFromSinglyLinkedList(SinglyLinkedList *sll,int index,int *success); 
void clearSinglyLinkedList(SinglyLinkedList *sll); 
int getSizeOfSinglyLinkedList(SinglyLinkedList *sll); 
void * getElementFromSinglyLinkedList(SinglyLinkedList *sll,int index,int *success); 
void releaseSinglyLinkedList(SinglyLinkedList *sll);
SinglyLinkedListIterator * getSinglyLinkedListIterator(SinglyLinkedList *sll); 
int hasMoreElementsInSinglyLinkedList(SinglyLinkedListIterator *iterator); 
void * getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *iterator,int *success); 
void releaseSinglyLinkedListIterator(SinglyLinkedListIterator *iterator); 
#endif
