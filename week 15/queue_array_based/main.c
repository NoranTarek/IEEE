#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void CreateQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void Append(QueueEntry e,Queue* pq)
{
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}
void Serve(QueueEntry *pe,Queue *pq)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}
int QueueEmpty(Queue* pq)
{
    return !pq->size;
}
int QueueFull(Queue* pq)
{
    return (pq->size == MAXQUEUE);
}
int QueueSize(Queue* pq)
{
    return pq->size;
}
void ClearQueue(Queue* pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void Display(QueueEntry e)
{
    printf("e is : %d \n",e);
}
void TraverseQueue(Queue *pq,void (*pf)(QueueEntry))
{
    int pos, s;
    for(pos=pq->front,s=0; s<pq->size ;s++)
    {
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%MAXQUEUE;
    }
}
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
