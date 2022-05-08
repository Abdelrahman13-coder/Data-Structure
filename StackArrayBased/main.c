
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct stack
{
    int arr[SIZE];
    int top;
    int size;
}Stack;

int isFull(Stack *ps);
int isEmpty(Stack *ps);
void stack_voidPush(int Copy_intValue, Stack * ps );
int stack_voidPop(Stack * ps);
void createStack(Stack * ps );
int stackSize(Stack *ps);
void printArr(Stack * ps );

int main()
{
    int topValue,sSize;
    Stack s;
    createStack(&s);
    stack_voidPush(5,&s);
    stack_voidPush(3,&s);
    stack_voidPush(4,&s);
    stack_voidPush(6,&s);
    topValue=stack_voidPop(&s);
    sSize = stackSize(&s);
    printf("%d\n",topValue);
    printf("%d\n",sSize);
    printArr(&s);
    return 0 ;
}
int isFull(Stack *ps)
{
    if(ps->top == SIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(Stack *ps)
{
    if(ps->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void stack_voidPush(int Copy_intValue, Stack * ps )
{
    if(isFull(ps))
    {
       printf("Stack overflow");
    }
    else
    {
       ps -> top++;
       ps->arr[ps->top] = Copy_intValue;
       ps->size ++;
    }
}
int stack_voidPop(Stack * ps)
{
    //check if stack not emty
    if(isEmpty(ps))
    {
        printf("Stack is empty");
        return 0;
    }
    else
    {
        int value = ps-> arr[ps->top];
        ps-> top--;
        ps->size--;
        return value;
        /* return ps->arr[ps->--top] */
    }

}
void createStack(Stack * ps )
{
    ps->top = -1;
    ps-> size = 0;
}
/*
int stackSize(Stack *ps)
{
    return ps->top;
}
*/
int stackSize(Stack *ps)
{
    return ps->size;
}
void printArr(Stack * ps )
{
    int i=stackSize(ps)-1;
    while(i!=-1)
    {
        printf("%d\n",ps->arr[i]);
        i--;
    }
}
