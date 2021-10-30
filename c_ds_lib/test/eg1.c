#include<tm_required.h> 
#include<tm_singly.h> 
#include<stdio.h> 
struct abc 
{ 
int x,y; 
char m; 
}; 
int main() 
{ 
int s,i; 
struct abc a1,a2,a3; 
struct abc *g; 
SinglyLinkedList *list=createSinglyLinkedList(&s); 
if(s==false) 
{ 
printf("Unable to create singly linked list\n"); 
return 0; 
} 
a1.x=10; 
a1.y=20; 
a1.m='A'; 
a2.x=400; 
a2.y=300; 
a2.m='Z'; 
a3.x=1000; 
a3.y=4030; 
a3.m='Q'; 
addToSinglyLinkedList(list,&a1,&s); 
addToSinglyLinkedList(list,&a2,&s); 
addToSinglyLinkedList(list,&a3,&s); 
i=0; 
while(i<=2) 
{ 
g=(struct abc *)getElementFromSinglyLinkedList(list,i,&s); 
printf("%d %d %c\n",g->x,g->y,g->m); 
i++; 
} 
return 0; 
}
