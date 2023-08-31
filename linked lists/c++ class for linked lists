#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class stack
{
private:
    node *top;
public:
    void push(int x);
    int pop();
    void display();
};
void stack::push(int x)
{
    node *t;
    t=new node;
    if(t==NULL)
        cout<<"Stack overflow ";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
int stack::pop()
{
    int x=-1;
    if(top==NULL)
        cout<<"stack underflow";
    else
    {
        x=top->data;
        node *p;
        p=top;
        top=top->next;
        delete p;
    }
    return x;
}
void stack::display()
{
    node *p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    stack stk;
    //stk.push(10);
    //stk.push(20);
    //stk.push(30);
    cout<<stk.pop();
    stk.display();
}
