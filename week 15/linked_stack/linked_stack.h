#ifndef LINKED_STACK_H_INCLUDED
#define LINKED_STACK_H_INCLUDED
#define StackEntry int

typedef struct StackNode
{
    StackEntry Entry;
    struct StackNode *Next;
}StackNode;
typedef struct Stack
{
    struct StackNode *Top;
    int Size;
}Stack;



#endif // LINKED_STACK_H_INCLUDED
