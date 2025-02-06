//#include <stdio.h>
//#include <stdlib.h>

void CreateStack(stack *ps)
{
    ps->top=0;
}
void push(StackEntry e, stack *ps)
{
    ps->entry[ps->top++]=e;
}
int StackFull(stack *ps)
{
    return ps->top == max_stack;
}
void pop(StackEntry *pe, stack *ps)
{
    *pe = ps->entry[--ps->top];
}
int StackEmpty(stack *ps)
{
    return !ps->top;
}
void StackTop(StackEnty *pe , stack *ps)
{
    *pe = ps->entry[ps->top-1];
}
int StackSize(stack *ps)
{
    return ps->top;
}
void ClearStack(stack *ps)
{
    ps->top=0;
}
void Display(StackEntry e)
{
    printf("number is : %d \n",e);
}
void TraverseStack(stack *ps ,void(*pf)(StackEntry))
{
    for(int i=ps->top;i > 0;i--)
    {
        (*pf)(ps->entry[i-1])
    }
}
