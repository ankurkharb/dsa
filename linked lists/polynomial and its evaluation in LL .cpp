#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    int coeff;
    int exp;
    struct node *next;
}*poly;
void create()
{
    struct node *t,*last;
    int num,i;
    cout<<"Enter number of terms\n";
    cin>>num;
    cout<<"Enter coeff and exp of each term\n";
    for(i=0;i<num;i++) {
        t = new node;
        cin >> t->coeff >> t->exp;
        t->next=NULL;
        if(poly==NULL)
        {
            poly=last=t;
        }
        else {
            last->next = t;
            last = t;
        }
    }
}
void display(struct node *p)
{
    while(p)
    {
        cout<<p->coeff<<"x"<<p->exp<<" + ";
        p=p->next;
    }
    cout<<"\n";
}
long eval(struct node *p,int x)
{
    long sum=0;
    while(p)
    {
        sum+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return sum;
}
int main()
{
    create();
    display(poly);
    cout<<eval(poly,2);
}
