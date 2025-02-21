#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Queue.c"

int main()
{
    Queue q;
    CreateQueue(&q);
    int x; scanf("%d", &x);
    Append(x,&q);
    int y;
    Serve(&y,&q);
    printf("%d\n",y);
    return 0;
}
