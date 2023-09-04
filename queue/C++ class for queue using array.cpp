#include<iostream>
using namespace std;
class queue
{
private:
    int size;
    int rear;
    int front;
    int *Q;
public:
    queue()
    {
        size=10;
        front=rear=-1;
        Q=new int[size];
    }
    queue(int size)
    {
        this->size=size;
        front=rear=-1;
        Q=new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void queue::enqueue(int x)
{
    if(rear==size-1)
        cout<<"Queue is Full\n";
    else
    {
        rear++;
        Q[rear]=x;
    }
}

int queue::dequeue()
{
    int x=-1;
    if(rear==front)
        cout<<"Queue is Empty\n";
    else
    {
        front++;
        x=Q[front];
    }
    return x;
}

void queue::display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<Q[i]<<" ";
    }
}
int main()
{
    class queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.display();
}
