#include<stdio.h>
#include<stdlib.h>
#include<tm_doubly.h>
#include<tm_required.h>
int main()
{
int success;
DoublyLinkedList *dll;
dll=createDoublyLinkedList(&success);
if(!success)
{
printf("Unable to allocate memory\n");
return 0;
}
int a1=100;
int a2=200;
int a3=300;
int a4=400;
int a5=500;
addToDoublyLinkedList(dll,&a1,&success);
addToDoublyLinkedList(dll,&a2,&success);
addToDoublyLinkedList(dll,&a3,&success);
addToDoublyLinkedList(dll,&a4,&success);
addToDoublyLinkedList(dll,&a5,&success);
DoublyLinkedListIterator *ii;
ii=getDoublyLinkedListIterator(dll,2);
while(hasMoreElementsInDoublyLinkedList(ii))
{
int *rr=(int *)getNextElementFromDoublyLinkedList(ii,&success);
printf("%d\n",*rr);
}
releaseDoublyLinkedListIterator(ii);
return 0;
}