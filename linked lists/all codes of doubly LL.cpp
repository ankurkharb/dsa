#include<iostream>
using namespace std;;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*head;
void create(int A[],int n)
{
    struct node *t,*last;
    head=new node;
    head->data=A[0];
    head->next=head->prev=NULL;
    last=head;

    int i;
    for(i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int len(struct node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void insert(struct node *p,int index,int x)
{
    int i;
    struct node *t;
    if(index<0 && index > len(p))
        return;
    if(index ==0)
    {
        t=new node;
        t->data=x;
        t->next=head;
        t->prev=NULL;
        head->prev=t;
        head=t;
    }
    else
    {
        t=new node;
        t->data=x;
        for(i=0;i<index-1;i++)
            p=p->next;
        t->prev=p;
        t->next=p->next;
        if(p->next)
            p->next->prev=t;
        p->next=t;

    }
}
int Delete(struct node *p,int index)
{
    int i,x;
    if(index <0 && index > len(p))
        return -1;
    if(index==1)
    {
        head=head->next;
        if(head)
            head->prev=NULL;
        x=p->data;
        delete p;
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        delete p;
        return x;
    }
}
void reverse(struct node *p)
{
    struct node *temp;
    while(p !=NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p!=NULL && p->next == NULL)
            head = p;
    }
}
void middleLL(struct node *p)
{
    struct node *q;
    q = p =head ;
    while(q!=NULL) {
        q = q->next;
        if (q)q = q->next;
        if (q)p = p->next;
    }
    cout<<"Middle element of LL is "<<p->data;
    cout<<"\n";
}
void middleLL2(struct node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    int index=len/2;
    struct node *q=head;
    for(int i=0;i<index-1;i++)
    {
        q=q->next;
    }
    cout<<"Midddle element of LL is "<<q->data;
    cout<<endl;
}
int main()
{
    int a[]={2,4,6,8,10,12,14,16,18};
    create(a,9);
   // cout<<len(head)<<endl;
   // insert(head,6,1);
   // Delete(head,6);
  //  reverse(head);
    middleLL2(head);
   // display(head);
}
