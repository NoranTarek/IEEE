//#define INFIX_TO_POSTFIX
#define EVALUATE_POSTFIX

#ifdef INFIX_TO_POSTFIX
typedef char Element type;
#define MAXELEMENT 100
typedef Elementtype StackEntry;
#define MAXSTACK MAXELEMENTS
#endif // INFIX_TO_POSTFIX

#ifdef EVALUATE_POSTFIX
typedef int Elementtype;
#define MAXELEMENT 100
typedef Elementtype StackEntry;
#define MAXSTACK MAXELEMENTS
#endif // EVALUATE_POSTFIX

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
