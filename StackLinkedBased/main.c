#include <stdio.h>
#include <stdlib.h>
typedef struct stacknode
{
   int data;
   struct stacknode * next;
}Stacknode;

typedef struct stack
{
    Stacknode* top;
    int size;
}Stack;


int isFull(Stack *ps);
int isEmpty(Stack *ps);
void stack_voidPush(int Copy_intValue, Stack * ps );
void stack_voidPop(Stack * ps,int *pd);
void createStack(Stack * ps );
int stackSize(Stack *ps);
void printArr(Stack * ps );
void clr(Stack *ps);
int main()
{
    int pd,sSize;
    Stack s;
    createStack(&s);
    stack_voidPush(5,&s);
    stack_voidPush(3,&s);
    stack_voidPush(4,&s);
    stack_voidPop(&s,&pd);
    printf("%d is poped \n",pd);
    sSize = stackSize(&s);
    printf("================================\n");
    printf("The stack size is %d\n",sSize);
    printArr(&s);
    return 0 ;
}

void createStack(Stack * ps )
{
    ps ->top = NULL;
    ps->size = 0;
}

void stack_voidPush(int Copy_intValue, Stack * ps )
{
   Stacknode *pn = (Stacknode*) malloc(sizeof(Stacknode));
   pn -> data = Copy_intValue;
   pn->next = ps->top;
   ps->top = pn;
   ps->size++;
}
void stack_voidPop(Stack * ps, int *pd)
{   if(isEmpty(ps))
    {
       printf("The stack is empty");
    }
    else
    {
       *pd = ps->top->data;
       Stacknode *pn = ps->top;
       ps->top = ps ->top->next;
       free(pn);
       ps->size--;
    }
}
int isFull(Stack *ps)
{
    return 0 ;
}
int isEmpty(Stack *ps)
{
    return ( ps->top == NULL);
}
void printArr(Stack * ps )
{
    Stacknode * pn = ps ->top;
    while(pn != NULL)
    {
       printf("%d\n",pn->data);
       pn = pn->next;
    }
}
void clr(Stack *ps)
{
    Stacknode * pn = ps ->top;
    while(ps->top!=NULL)
    {
        ps->top = ps ->top -> next;
        free(pn);
        pn = ps ->top;
    }
    ps->size = 0;
}
int stackSize(Stack *ps)
{
    return ps->size;
}
/*
void clr(Stack *ps)
{
    Stacknode * pn = ps ->top;
    while(pn!=NULL)
    {
        ps->top = ps ->top -> next;
        free(pn);
        pn = ps ->top;
    }
}
*/
