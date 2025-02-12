#include <stdio.h>
#include <stdlib.h>
#include "linked_stack.h"

void Create_Stack(Stack *ps)
{
    ps->Top=NULL;
    ps->Size=0;
}
void Push(StackEntry e,Stack *ps)
{
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    pn->Entry=e;
    pn->Next=ps->Top;
    ps->Top=pn;
    ps->Size++;
}
void Pop(StackEntry *pe,Stack *ps)
{
    StackNode *pn;
    *pe=ps->Top->Entry;
    pn=ps->Top;
    ps->Top=ps->Top->Next;
    free(pn);
    ps->Size--;
}
int StackEmpty(Stack *ps)
{
    return ps->Top==NULL;
}
int stackFull(Stack *ps)
{
    return 1; //صعب جدا تكون بصفر لان دا معناها ان الميمورى اللى اتملت مش مجرد ستاك
}
void ClearStack(Stack *ps)
{
    StackNode *pn=ps->Top;
    while(pn)
    {
        pn=pn->Next;
        free(ps->Top);
        ps->Top=pn;
    }
    ps->Size=0;
}
void Display(int e)
{
    printf("number is : %d \n",e);
}
void TraverseStack(Stack *ps,void(*pf)(int))
{
    StackNode *pn=ps->Top;
    while(pn)
    {
        (*pf)(pn->Entry);
        pn=pn->Next;
    }
}
int StackSize(Stack *ps)
{
    return ps->Size;
}

int main()
{
    Stack s;
    while(1)
    {
        printf("select the option : \n");
        printf("1-CreateStack. \n2-Push.\n3-Pop.\n4-IsStackEmpty.\n5-IsStackFull.\n6-ClearStack.\n7-TraverseStack.\n8-GetStackSize.\n" );
        int option;
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            Create_Stack(&s);
            break;
        case 2:
            if(stackFull(&s))
                printf("stack is full\n");
            else
            {
                printf("enter the data \n");
                int data;
                scanf("%d", &data);
                Push(data,&s);
            }
            break;
        case 3:
            if(StackEmpty(&s))
                printf("stack is empty\n");
            else
            {
                int popdata;
                Pop(&popdata, &s);
            }
            break;
        case 4:
            if(StackEmpty(&s))
                printf("stack is empty\n");
            else
                printf("stack is not empty\n");
            break;
        case 5:
            if(stackFull(&s))
                printf("stack is full\n");
            else
                printf("stack is not full\n");
            break;
        case 6:
            ClearStack(&s);
            break;
        case 7:
            TraverseStack(&s,Display);
            break;
        case 8:
            printf("the size is %d",StackSize);
            break;
        }
    }
    return 0;
}
