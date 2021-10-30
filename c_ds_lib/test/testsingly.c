#include<tm_required.h> 
#include<tm_singly.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
struct Student 
{ 
int rollNumber; 
char *name; 
}; 
void addStudent(SinglyLinkedList *list,SinglyLinkedListIterator *ite) 
{ 
int found,rollNumber,success; 
char name[22]; 
struct Student *s; 
char m; 
printf("Enter roll number:"); 
scanf("%d",&rollNumber); 
fflush(stdin); 
if(rollNumber<=0) 
{ 
printf("Invalid roll number\n"); 
return; 
} 
found=0;
ite=getSinglyLinkedListIterator(list);
while(hasMoreElementsInSinglyLinkedList(ite))
{
if(rollNumber==ite->node->*s->rollNumber)
{
found=1;
break;
}
}
if(found==1)
{
printf("That roll Number is already alotted to %s\n",ite->node->*s->name);
return;
}
printf("Enter name:"); 
fgets(name,22,stdin); 
fflush(stdin); 
name[strlen(name)-1]='\0'; 
printf("Save(Y/N):"); 
m=getchar(); 
if(m!='Y' && m!='y') 
{ 
printf("Student not added\n"); 
return; 
} 
s=(struct Student *)malloc(sizeof(struct Student)); 
if(s==NULL) 
{ 
printf("Unable to add student, insufficient memory\n"); 
return; 
} 
s->name=(char *)malloc(sizeof(char)*(strlen(name)+1)); 
if(s->name==NULL) 
{
free(s); 
printf("Unable to add student, insufficient memory\n"); 
return; 
} 
s->rollNumber=rollNumber; 
strcpy(s->name,name); 
addToSinglyLinkedList(list,s,&success); 
if(!success) 
{ 
free(s->name); 
free(s); 
printf("Unable to add student, insufficient memory\n"); 
return; 
} 
printf("Student added\n"); 
} 
void displayListOfStudents(SinglyLinkedList *list) 
{ 
struct Student *s; 
int success; 
SinglyLinkedListIterator *iterator; 
iterator=getSinglyLinkedListIterator(list); 
while(hasMoreElementsInSinglyLinkedList(iterator)) 
{ 
s=(struct Student *)getNextElementFromSinglyLinkedList(iterator,&success); 
printf("%d,%s\n",s->rollNumber,s->name); 
} 
}
int main() 
{ 
int ch; 
SinglyLinkedListIterator *iterator; 
int success; 
struct Student *s; 
SinglyLinkedList *list=createSinglyLinkedList(&success); 
if(!success) 
{ 
printf("Insufficient memory\n"); 
return 0; 
} 
while(1) 
{ 
printf("1.Add\n"); 
printf("2.Remove\n"); 
printf("3.Display size\n"); 
printf("4.List\n");
printf("5.Clear\n"); 
printf("6.Insert\n"); 
printf("7.Exit\n"); 
printf("Enter your choice:"); 
scanf("%d",&ch); 
fflush(stdin); 
if(ch==1) addStudent(list,ite); 
if(ch==4) displayListOfStudents(list); 
if(ch==7) break; 
} 
iterator=getSinglyLinkedListIterator(list); 
while(hasMoreElementsInSinglyLinkedList(iterator)) 
{ 
s=(struct Student *)getNextElementFromSinglyLinkedList(iterator,&success); 
free(s->name); 
free(s); 
} 
releaseSinglyLinkedList(list); 
return 0; 
} 

