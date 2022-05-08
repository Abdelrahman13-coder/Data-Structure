#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
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
    Queue q;
    int value,qSize;
    createQueue(&q);
    inqueue(5,&q);
    inqueue(6,&q);
    inqueue(7,&q);
    inqueue(9,&q);
    inqueue(10,&q);
    dequeue(&q,&value);
    printf("%d\n",value);
    qSize=queueSize(&q);
    printf("The queue size is %d\n",qSize);
    return 0;
}

void createQueue(Queue * pq )
{
    pq-> front = 0;
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
       if(pq->rear == SIZE -1)
       {
         pq->rear = 0;
       }
       else
       {
           pq->rear ++;
       }
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

        if(pq ->front == SIZE-1)
        {
            pq->front = 0;
        }
        else
        {
            pq->front ++;
        }
        pq->size--;
    }
}

int queueSize(Queue *pq)
{
    return pq->size;
}
int isEmpty(Queue *pq)
{
    return (pq->size ==0);
}
int isFull(Queue *pq)
{
    return (pq->size==SIZE);
}
