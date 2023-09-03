#include<iostream>
using namespace std;
struct queue
{
    int size ;
    int rear;
    int front;
    int *Q;
};
void create(struct queue *q, int size)
{
    q->size=size;
    q->Q=new int[q->size];
    q->rear=q->front=-1;
}
void enqueue(struct queue *q,int x)
{
    if(q->rear == q->size-1)
        cout<<"Queue is full ";
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->rear==q->front)
        cout<<"Queue is Empty";
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        cout<<q.Q[i]<<" ";
    }
}
int main()
{
    struct queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    dequeue(&q);
    display(q);
}
