header file
struct node
{
    node *lchild;
    int data;
    node *rchild;
};
struct queue
{
    int size;
    int rear;
    int front;
    node **Q;
};
void create(struct queue *q,int size)
{
    q->size=size;
    q->rear=q->front=0;
    q->Q=new node*[q->size];
}
void enqueue(struct queue *q,node* x)
{
    if((q->rear+1)%q->size==q->front)
        std::cout<<"Stack is Full \n";
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
node* dequeue(struct queue *q)
{
    node* x=NULL;
    if(q->rear==q->front)
        std::cout<<"Queue  is Empty\n";
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isempty(struct queue q)
{
    return q.front==q.rear;
}


#include<iostream>
#include "Queue.h"
using namespace std;
struct node *root=NULL;
void Treecreate()
{
    int x;
    struct node *p,*t;
    struct queue q;
    create(&q,100);
    cout<<"Enter value of root node";
    cin>>x;
    root=new node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isempty(q))
    {
        p= dequeue(&q);
        cout<<"Enter left child of "<<p->data;
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->rchild=t->lchild=NULL;
            p->lchild=t;
            enqueue(&q,t);

        }
        cout<<"Enter right child of "<<p->data;
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->rchild=t->lchild=NULL;
            p->rchild=t;
            enqueue(&q,t);

        }
    }
}
void preorder(struct node *p)
{
    if(p) {
        cout << p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void posorder(struct node *p)
{
    if(p) {
        posorder(p->lchild);
        posorder(p->rchild);
        cout << p->data;
    }
}

int main()
{
    Treecreate();
    posorder(root);
}
