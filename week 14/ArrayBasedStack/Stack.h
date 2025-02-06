#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define max_stack     100
#define T             d
#define StackEntry int
typedef struct Stack
{
    int top;
    int entry[max_stack];
}stack;
void CreateStack(stack *ps);
void push(StackEntry e, stack *ps);
int StackFull(stack *ps);
void pop(StackEntry *pe, stack *ps);
int StackEmpty(stack *ps);
void StackTop(StackEntry *pe , stack *ps);
int StackSize(stack *ps);
void ClearStack(stack *ps);
void Display(StackEntry e);
void TraverseStack(stack *ps ,void(*pf)(StackEntry));

#endif // STACK_H_INCLUDED
