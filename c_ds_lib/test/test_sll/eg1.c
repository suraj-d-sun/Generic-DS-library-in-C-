#include<stdio.h>
#include<stdlib.h>
#include<tm_singly.h>
#include<tm_required.h>
int main()
{
int success;
SinglyLinkedList *sll;
sll=createSinglyLinkedList(&success);
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
addToSinglyLinkedList(sll,&a1,&success);
addToSinglyLinkedList(sll,&a2,&success);
addToSinglyLinkedList(sll,&a3,&success);
addToSinglyLinkedList(sll,&a4,&success);
addToSinglyLinkedList(sll,&a5,&success);
SinglyLinkedListIterator *ii;
ii=getSinglyLinkedListIterator(sll);
while(hasMoreElementsInSinglyLinkedList(ii))
{
int *rr=(int *)getNextElementFromSinglyLinkedList(ii,&success);
printf("%d\n",*rr);
}
releaseSinglyLinkedListIterator(ii);
return 0;
}