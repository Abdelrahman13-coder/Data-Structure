#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct queue
{
    int arr[SIZE];
    int front;
    int rear;
    int size;
}Queue;

int isFull(Queue *ps);
int isEmpty(Queue *pq);
void inqueue(int Copy_intValue, Queue * ps );
void dequeue(Queue * pq,int *pd);
void createQueue(Queue * pq );
int queueSize(Queue *pq);
void printArr(Queue * pq );
//void clr(Stack *ps);
int main()
{
    int topValue,sSize;
    Queue q;
    createQueue(&q);
    inqueue(5,&q);
    inqueue(3,&q);
    inqueue(4,&q);
    inqueue(6,&q);
    topValue=queueSize(&q);
    sSize = stackSize(&q);
    printf("%d\n",topValue);
    printf("%d\n",sSize);
    printArr(&s);
}

void createQueue(Queue * pq )
{
    pq-> front = -1;
    pq -> rear = -1;
    pq->size = 0;
}
void inqueue(int Copy_intValue, Queue * pq )
{
    if(isFull(pq))
    {
        printf("Queue is full");
    }
    else
    {
       if(pq->front ==-1)
       {
         pq->front = 0;
       }
        pq->rear++;
        pq->arr[pq->rear]= Copy_intValue;
        pq->size ++;
    }

}
void dequeue(Queue* pq, int *pd)
{
    if(isEmpty(pq))
    {
       printf("Queue is empty");
    }
    else
    {
        *pd = pq->arr[pq->front];
        pq->front --;
        pq->size--;
        if(pq->front > pq->rear)
        {
           pq->front =pq->rear = -1;
        }
    }
}
void printArr(Queue * pq )
{
    int i;
    if(isEmpty(pq))
    {
      printf("The queue is empty");
    }
    else
    {
        for(i=pq->front;i<= pq-> rear ; i++)
        {
            printf("%d\n",pq->arr[i]);
        }
    }
}
int queueSize(Queue *pq)
{
    return pq->size;
}
int isEmpty(Queue *pq)
{
    return (pq->front ==-1);
}
int isFull(Queue *pq)
{
    return (pq-> rear == SIZE-1);
}
