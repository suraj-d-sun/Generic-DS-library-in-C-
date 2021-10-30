#include<stdio.h>
#include<stdlib.h>
#include<tm_stack.h>
#include<tm_required.h>
int main()
{
int success;
Stack *stk;
stk=createStack(&success);
if(!stk)
{
printf("Unable to allocate Stack memory.");
return 0;
}
int num1=100;
int num2=200;
int num3=300;
int num4=400;
int num5=500;
pushOnStack(stk,&num1,&success);
pushOnStack(stk,&num2,&success);
pushOnStack(stk,&num3,&success);
pushOnStack(stk,&num4,&success);
pushOnStack(stk,&num5,&success);
int size=getSizeOfStack(stk);
printf("Size of stack is %d\n",size);
int *ptr;
while(isStackEmpty)
{
ptr=(int *)popFromStack(stk,&success);
printf("%d\n",*ptr);
}
releaseStack(stk);
return 0;
}