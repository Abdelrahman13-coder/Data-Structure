#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct stack
{
    char *arr[SIZE];
    int top;
    int size;
}Stack;

int isFull(Stack *ps);
int isEmpty(Stack *ps);
void stack_voidPush(char Copy_intValue, Stack * ps );
int stack_voidPop(Stack * ps);
void createStack(Stack * ps );
int stackSize(Stack *ps);
void printArr(Stack * ps );
void reverse(char str[],Stack * ps);
int main()
{
    int i,size;
    char str[] ="ALY";
    Stack s;
    createStack(&s);
    for(i=strlen(str);i>=0;i--)
    {

        stack_voidPush(str[i],&s);
    }
    size=stackSize(&s);
    printArr(&s);
    printf("The stack size is %d\n",size);
    reverse(str,&s);
    printf("============================\n");
    printf("Reversed stack\n");
    printArr(&s);


    return 0;
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
void createStack(Stack * ps )
{
    ps->top = -1;
    ps-> size = 0;
}

void reverse(char str[],Stack * ps)
{
    char arr[strlen(str)];
    int i;
   // if(str[i]!='\0')
   // {
        for(i=0;i<=strlen(str);i++)
        {
            arr[i]=stack_voidPop(ps);
        }
        for(i=0;i<=strlen(str);i++)
        {
            stack_voidPush(arr[i],ps);
        }
   // }

}

void stack_voidPush(char Copy_intValue, Stack * ps )
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
        printf("Stack is empty\n");
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
int stackSize(Stack *ps)
{
    return ps->size;
}
void printArr(Stack * ps )
{
    int i=stackSize(ps)-1;
    while(i!=-1)
    {
        printf("%c\n",ps->arr[i]);
        i--;
    }
}

/*

void reverse(char str[],Stack * ps)
{
    int len = strlen(str);
    int i;

    for(i=0;i<len;i++)
        stack_voidPush(str[i],ps);

    for(i=0;i<len;i++)
        stack_voidPop(ps);
}
*/
