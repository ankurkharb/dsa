#include<iostream>
#include <string.h>
using namespace std;
struct node
{
    char data ;
    node *next;
}*top=NULL;
void push(char x)
{
    struct node *t;
    t=new node;
    if(t==NULL)
        cout<<"Stack is full";
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    char x=-1;
    struct node *t;
    if(top==NULL)
        cout<<"Stack is empty\n";
    else
    {
        t=top;
        x=top->data;
        top=top->next;
        delete t;
    }
    return x;
}
char stacktop()
{
    return top->data;
}
int parenthesis(char *exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top==NULL)
                return 0;
            else pop();
        }
    }
    if(top== NULL)
        return true;
    else
        return false;
}
int precedence(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else
        return 0;
}
int isoperand(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')')
        return 0;
    else
        return 1;
}
int outprecedence(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 3;
    else if(c=='^')
        return 6;
    else if(c=='(')
        return 7;
    else if(c==')')
        return 0;
    else
        return -1;
}
int inprecedence(char c)
{
    if(c=='+' || c=='-')
        return 2;
    else if(c=='*' || c=='/')
        return 4;
    else if(c=='^')
        return 5;
    else if(c=='(')
        return 0;
    else
        return -1;
}
char * inToPos(char *infix)
{
    int i=0,j=0;
    int len=strlen(infix);
    char *postfix;
    postfix=new char[len+2];
    while(infix[i]!='\0')
    {
        if(isoperand(infix[i])){
            postfix[j++]=infix[i++];}
        else
        {
            if (top == NULL || outprecedence(infix[i]) > inprecedence(top->data)) {
                push(infix[i++]);
            } else if (outprecedence(infix[i]) < inprecedence(top->data))
                postfix[j++] = pop();
            else {
                pop();
                i++;
            }
        }
    }
    while(top!=NULL)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    push('#');
    char A[]="3*5+6/2-4";
    char * ans= inToPos(A);
    cout<<ans;
}
