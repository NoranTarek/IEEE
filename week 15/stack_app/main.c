#include <stdio.h>
#include <stdlib.h>
#include "Stack_app.h"

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

int StackTop(Stack *ps)
{
    return ps->Top;
}

int IsDigit(char c)
{
    return (c>='0' && c<='9');
}

int Precedent(char op1,char op2)
{
    if(op1=='$')
        return 1;
    if((op1=='*') || (op1=='/'))
        return (op2!='$');
    if((op1=='+') || (op1=='-'))
        return ((op2!='$')&&(op2!='*')&&(op2!='/'));
    return 0;
}

double Oper(char c,double op1,double op2)
{
    switch (c)
    {
        case '+': return(op1+op2);
        case '-': return(op1-op2);
        case '*': return(op1*op2);
        case '/': return(op1/op2);
        case '$': return(pow(op1,op2));
    }
}

void InfixToPostfix(char infix[],char postfix[])
{
    int i,j;
    char op,c;
    Stack s;
    Create_Stack(&s);
    for(i=0 , j=0; (c=infix[i])!='\0'; i++)
    {
        if(IsDigit(c))
            postfix[j++]=c;
        else
        {
            if(!StackEmpty(&s))
                Push(op,&s);
            while(!StackEmpty(&s) && Precedent(op,c))
            {
                Pop(&op,&s);
                postfix[j++]=op;
                if(!StackEmpty(&s))
                    Push(op,&s);
            }
        }
        Push(c, &s);
    }
    while(!StackEmpty(&s))
    {
        Pop(&op,&s);
        postfix[j++]=op;
    }
    postfix[j]='\0';
}

double EvaluatePostfix(char expr[])
{
    int i;
    char c;
    double op1,op2,val;
    Stack s;
    Create_Stack(&s);
    for(i=0 ; (c=expr[i])!='\0'; i++)
    {
        if(IsDigit(c))
            Push((double)(c-'0'),&s);//علشان طرح الاتنين اسكيو كود يساوى القيمة اللى هى من 0 ل 9
        else
        {
            Pop(&op2,&s);
            Pop(&op1,&s);
            val=Oper(c,op1,op2);
            Push(val,&s);
        }
    }
    Pop(&val,&s);
    return val;
}
int main()
{
    //for in to post
    char infix[]="1+2*3$4/5+6";
    char postfix[80];
    InfixToPostfix(infix,postfix);
    printf("\n %s",postfix);
    //for evaluation
    char expr[]="354*+2$";
    double x;
    x = EvaluatePostfix(expr);
    printf("\n %f",x);
    getch();
    return 0;
}
