#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
    int Data;
    struct listnode* Next;
}ListNode;

typedef struct list
{
    int size;
    ListNode* head;
}List;

void List_voidInit(List* pl);
void List_voidInsertList(int Pos, List* pl, int Copy_intValue);
void List_voidReplaceList(int Pos, List* pl, int Copy_intValue);
void List_voidDeleteList(int Pos, List* pl, int* pd);
void List_voidRetriveList(int Pos, List* pl, int* pd);
int  List_intIsEmpty(List* pl);
int  List_intIsFull(List* pl);
int  List_intSize(List* pl);
void List_voidPrint(List* pl);
void List_voidDestroyList(List* pl);

int main()
{
    int size, RetrivedValue;
    List L;
    List_voidInit(&L);

    List_voidInsertList(0,&L,10);
    List_voidInsertList(1,&L,5);
    List_voidInsertList(2,&L,2);

    size= List_intSize(&L);

    printf("List size is %d\n", size);
    List_voidPrint(&L);

    List_voidRetriveList(2, &L, &RetrivedValue);
    printf("The RetrivedValue is %d\n", RetrivedValue);

    List_voidDeleteList(5,&L, &RetrivedValue);
    printf("The RetrivedValue is  %d\n", RetrivedValue);

    size= List_intSize(&L);

    printf("List size is %d\n", size);
}

void List_voidInit(List* pl)
{
    pl->head = NULL;
    pl->size =0;
}

int  List_intIsEmpty(List* pl)
{
    return (pl->head == NULL);
}

int  List_intIsFull(List* pl)
{
    return 0;
}

int  List_intSize(List* pl)
{
    return (pl->size);
}

void List_voidInsertList(int Pos, List* pl, int Copy_intValue)
{
    ListNode* q;
    int i;
    ListNode* pn = (ListNode*)malloc(sizeof(ListNode));
    pn->Data =   Copy_intValue;
    pn->Next =   NULL;

    if(Pos == 0)
    {
        pn->Next = pl->head;
        pl->head = pn;
    }
    else
    {
        for(q = pl->head, i=0; i< Pos-1; i++)
        {
            q = q->Next;
        }
        pn ->Next= q->Next;
        q->Next= pn;
    }

    pl->size++;
}

void List_voidReplaceList(int Pos, List* pl, int Copy_intValue)
{
    int i;
    ListNode* q;
    for(q= pl->head, i=0; i<Pos; i++)
    {
        q = q->Next;
    }
    q->Data= Copy_intValue;
}

void List_voidDeleteList(int Pos, List* pl, int* pd)
{
    int i;
    ListNode *q, *tmp;

    if(Pos==0)
    {
        *pd = pl->head->Data;
        tmp = pl->head->Next;
        free(pl->head);
        pl->head= tmp;
    }
    else
    {
        for(q= pl->head, i=0; i<Pos-1; i++)
        {
            q = q->Next;
        }
       *pd = q->Next->Data;
        tmp= q->Next->Next;
        free(q->Next);
        q->Next = tmp;
    }
    pl->size--;
}

void List_voidRetriveList(int Pos, List* pl, int* pd)
{
    int i;
    ListNode* q;

    for(q= pl->head, i=0; i< Pos; i++)
    {
        q = q->Next;
    }
    *pd= q->Data;
}

void List_voidPrint(List* pl)
{
    ListNode* q= pl->head;

    while(q != NULL)
    {
        printf("%d\t", q->Data);
        q= q->Next;
    }
}

void List_voidDestroyList(List* pl)
{
    ListNode* tmp;

    while(pl->head != NULL)
    {
        tmp = pl->head->Next;
        free(pl->head);
        pl->head= tmp;
    }

    pl->size=0;
}
