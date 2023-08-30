#include<iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *s;
};
void create(struct stack *st)
{
    st->top=-1;
    cout<<"Enter size of stack";
    cin>>st->size;
    st->s=new int[st->size];
}
void push(struct stack *st,int x)
{

    if(st->top==st->size-1)
        cout<<"Stack overflow ";
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
        cout<<"stack underflow ";
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
int peek(struct stack st,int pos)
{
    int x=-1;
    if(st.top-pos+1<0)
        cout<<"Invalid position";
    else
    {
        x=st.s[st.top-pos+1];
    }
    return x;
}
int stacktop(struct stack st)
{
    if(st.top==-1)
        return -1;
    else
        return st.s[st.top];
}
int isempty(struct stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}
int isfull(struct stack st)
{
    if(st.top==st.size-1)
        return 1;
    else
        return 0;
}
void display(struct stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        cout<<st.s[i]<<" ";
    }
}
int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    push(&st,60);
    //cout<<peek(st,3);
   // cout<<isempty(st);
    //cout<<isfull(st);
    cout<<stacktop(st);
   // display(st);
}
