#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef int QueueEntry;
typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;
typedef struct queue
{
  QueueNode *front;
  QueueNode *rear;
  int size;
}Queue;

void CreateQueue(Queue *pq);

void Append(QueueEntry e,Queue* pq);

void Serve(QueueEntry *pe,Queue* pq);

int QueueEmpty(Queue* pq);

int QueueFull(Queue* pq);

int QueueSize(Queue* pq);

void ClearQueue(Queue* pq);

void Display(QueueEntry e);

void TraverseQueue(Queue* pq,void (*pf)(QueueEntry));


#endif // QUEUE_H_INCLUDED
