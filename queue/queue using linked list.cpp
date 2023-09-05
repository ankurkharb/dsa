#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
}*front,*rear;
void enqueue(int x)
{
    struct node *t;
    t=new node;
    if(t==NULL)
        cout<<"stack is full";
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}
int dequeue()
{
    int x=-1;
    struct node *t;
    if(front==NULL)
        cout<<"Queue is Empty\n";
    else
    {
        t=front;
        x=t->data;
        front=front->next;
        delete t;
    }
    return x;
}
void display()
{
    struct node *p;
    p=front;
    while(p)
    {
        cout<<p->data;
        p=p->next;
    }
    cout<<"\n";
}
int main()
{
    struct node t;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    cout<<dequeue();
}
