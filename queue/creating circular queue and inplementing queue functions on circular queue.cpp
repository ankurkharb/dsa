#include<iostream>
using namespace std;
struct queue
{
    int size;
    int rear;
    int front;
    int *Q;
};
void create(struct queue *q,int size)
{
    q->size=size;
    q->rear=q->front=0;
    q->Q=new int[q->size];
}
void enqueue(struct queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        cout<<"Stack is Full \n";
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->rear==q->front)
        cout<<"Queue  is Empty\n";
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct queue q)
{
    int i=q.front+1;
    do
    {
        cout<<q.Q[i]<<" ";
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    cout<<endl;
}
int main()
{
    queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    dequeue(&q);
    display(q);
}
