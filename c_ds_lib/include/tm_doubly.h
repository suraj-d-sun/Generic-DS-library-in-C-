#ifndef __tm__$_tm_doubly_h 
#define __tm__$_tm_doubly_h 234 
struct _$_DLL_Node 
{ 
void *ptr; 
struct _$_DLL_Node *next; 
struct _$_DLL_Node *previous;
}; 
typedef struct _$_DoublyLinkedList 
{ 
struct _$_DLL_Node *start; 
struct _$_DLL_Node *end; 
int count; 
}DoublyLinkedList; 
typedef struct __$_DoublyLinkedListIterator 
{ 
struct _$_DLL_Node *node; 
int direction;
}DoublyLinkedListIterator; 
DoublyLinkedList * createDoublyLinkedList(int *success); 
void addToDoublyLinkedList(DoublyLinkedList *dll,void *ptr,int *success); 
void insertInDoublyLinkedList(DoublyLinkedList *dll,void *ptr,int index,int *success); 
void * removeFromDoublyLinkedList(DoublyLinkedList *dll,int index,int *success); 
void clearDoublyLinkedList(DoublyLinkedList *dll); 
int getSizeOfDoublyLinkedList(DoublyLinkedList *dll); 
void * getElementFromDoublyLinkedList(DoublyLinkedList *dll,int index,int *success); 
void releaseDoublyLinkedList(DoublyLinkedList *dll);
DoublyLinkedListIterator * getDoublyLinkedListIterator(DoublyLinkedList *dll,int direction); 
int hasMoreElementsInDoublyLinkedList(DoublyLinkedListIterator *iterator); 
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *iterator,int *success); 
void releaseDoublyLinkedListIterator(DoublyLinkedListIterator *iterator); 
#endif
