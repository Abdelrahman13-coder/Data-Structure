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
int isMatchingPair(char c1, char c2);
int areBracketsBalanced(char arr[],Stack *ps);
int main()
{
    int i,size;
    char str[] ="[[}]";
    Stack s;
    createStack(&s);

    int flag;
    printf("Enter the string with the brackets and etc.\n");
    //fgets(str, sizeof(str),stdin);
    flag=areBracketsBalanced(str,&s);
    if(flag==1){
        printf("Balanced\n");
    }
    else
    {
        printf("Not balanced\n");
    }

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


int isMatchingPair(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
    {
        return 1;
    }
    else if (c1 == '{' && c2 == '}')
    {
        return 1;
    }
    else if (c1 == '[' && c2 == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int areBracketsBalanced(char arr[],Stack *ps)
{
    int i = 0;
    while (arr[i])
    {
        if (arr[i] == '{' || arr[i] == '(' || arr[i] == '[')
        {
            stack_voidPush(arr[i],ps);
        }

        if (arr[i] == '}' || arr[i] == ')'|| arr[i] == ']')
        {

            if (!isMatchingPair(stack_voidPop(ps), arr[i]))
            {
                return 0;
            }
        }
        i++;
    }

    if (ps->size==0)
        return 1;
    else
        return 0;
}
