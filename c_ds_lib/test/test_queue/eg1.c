#include<stdio.h>
#include<stdlib.h>
#include<tm_queue.h>
#include<tm_required.h>
int main()
{
int success;
Queue *que;
que=createQueue(&success);
if(!que)
{
printf("Unable to allocate Queue memory.");
return 0;
}
int num1=100;
int num2=200;
int num3=300;
int num4=400;
int num5=500;
pushOnQueue(que,&num1,&success);
pushOnQueue(que,&num2,&success);
pushOnQueue(que,&num3,&success);
pushOnQueue(que,&num4,&success);
pushOnQueue(que,&num5,&success);
int size=getSizeOfQueue(que);
printf("Size of queue is %d\n",size);
int *ptr;
while(isQueueEmpty)
{
ptr=(int *)popFromQueue(que,&success);
printf("%d\n",*ptr);
}
printf("******\n");
releaseQueue(que);
return 0;
}