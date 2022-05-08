#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
using namespace std;
typedef struct stack
{
    int arr[SIZE];
    int top;
}Stack;

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
       ps ->top++;
       ps->arr[ps->top] = Copy_intValue;
    }
}
int stack_voidPop(Stack * ps)
{
    //check if stack not emty
    if(isEmpty)
    {
        return ps-> arr[ps->top];
        ps-> top--;
        /* return ps->arr[ps->--top] */
    }
    else
    {
        printf("Stack is empty");
        return 0;
    }

}
void createStack(Stack * ps )
{
    ps->top = -1;
}
int stackSize(Stack *ps)
{
    return ps->top;
}
void printArr(Stack * ps )
{
    int i=ps->top;
    while(i!=-1)
    {
        printf("%d\n",ps->arr[i]);
        i--;
    }
}

int main()
{
    int topValue,sSize;
    Stack s;
    createStack(&s);
    stack_voidPush(5,&s);
    stack_voidPush(3,&s);
    stack_voidPush(4,&s);
    topValue=stack_voidPop(&s);
    sSize = stackSize(&s);
    printf("%d\n",topValue);
    printf("%d\n",sSize);
    printArr(&s);
    return 0 ;
}
