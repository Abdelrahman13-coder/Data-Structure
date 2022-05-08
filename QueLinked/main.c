#include <stdio.h>
#include <stdlib.h>

/*structure for Queue nodes*/
typedef struct queuenode
{
    int data;
    struct queuenode * next;
}QueueNode;

typedef struct queue
{
    int size;
    QueueNode* front;
    QueueNode* rear;
}Queue;

void Queue_voidInit(Queue* pq);
void Queue_voidEnQueue(int Copy_intValue, Queue* pq);
int  Queue_intIsFull(Queue* pq);
void Queue_voidDeQueue(Queue* pq, int* pd);
int  Queue_intIsEmpty(Queue* pq);
int  Queue_intSize(Queue* pq);
void Queue_voidPrint(Queue* pq);
void Queue_voidClear(Queue *pq);
int main()
{
    int size, Peek;
    Queue q;
    Queue_voidInit(&q);
    Queue_voidEnQueue(7,&q);
    Queue_voidEnQueue(4,&q);
    Queue_voidEnQueue(1,&q);
    Queue_voidEnQueue(9,&q);
    size = Queue_intSize(&q);
    printf("Queue size is %d\n", size);

    Queue_voidDeQueue(&q,&Peek);
    printf("Front value is  %d\n", Peek);
    size = Queue_intSize(&q);
    printf("Queue size is %d\n", size);
    Queue_voidDeQueue(&q,&Peek);
    printf("Front value is %d\n", Peek);
    size = Queue_intSize(&q);
    printf("Queue size is  %d\n", size);
    Queue_voidPrint(&q);
    Queue_voidClear(&q);
    return 0;
}

void Queue_voidInit(Queue* pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

void Queue_voidEnQueue(int Copy_intValue, Queue* pq)
{
    QueueNode* pn= (QueueNode*) malloc(sizeof(QueueNode));

    pn->data = Copy_intValue;
    pn->next = NULL;

    if(Queue_intIsEmpty(pq))
    {
        pq->front = pn;
    }
    else
    {
        pq->rear->next = pn;
    }
    pq->rear = pn;
    pq->size++;
}

int  Queue_intIsFull(Queue* pq)
{
    return 0;
}

void Queue_voidDeQueue(Queue* pq, int* pd)
{
    if(Queue_intIsEmpty(pq))
    {
        printf("Queue is empty");
    }
    else
    {
        QueueNode* pn = pq->front;
        *pd = pn->data;
        /*Update Front of the Queue*/
        pq->front = pq->front->next;
        /*Deallocate the Old FrontNode*/
        free(pn);
        if(Queue_intIsEmpty(pq))
        {
            pq->rear = NULL;
        }
        pq->size--;
    }
}

int  Queue_intIsEmpty(Queue* pq)
{
    return (pq->front == NULL);
}

int  Queue_intSize(Queue* pq)
{
    return pq->size;
}

void Queue_voidPrint(Queue* pq)
{
    QueueNode *pn = pq ->front;
    while(pn!=NULL)
    {
        printf("%d\n",pn->data);
        pn = pn->next;
    }
}

void Queue_voidClear(Queue *pq)
{
    while(!Queue_intIsEmpty(pq))
    {
        pq->rear = pq->front ->next;
        free(pq->rear);
        pq->front = pq->rear;
    }
    pq->size =0;
}
