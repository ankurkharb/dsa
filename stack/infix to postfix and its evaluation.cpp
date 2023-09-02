#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    int data;
    node *next;
} * top = NULL;

void push(int x)
{
    struct node *t;
    t = new node;
    if (t == NULL)
        cout << "stack is full\n";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x = -1;
    struct node *t;
    if (top == NULL)
        cout << "stack underflow\n";
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void display()
{
    struct node *p;
    p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

int isoperand(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

char *inToposfix(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    long length = strlen(infix);
    postfix = new char[length + 1];  // Allocate memory after declaring postfix

    while (infix[i] != '\0')
    {
        if (isoperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (top == NULL || precedence(infix[i]) > precedence(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }

    while (top != NULL)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}

int eval(char *postfix)
{
    char i = 0;
    int x1, x2, r = 0;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isoperand(postfix[i]))
        {
            push(postfix[i] - '0'); // Convert character to integer
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
                case '+':
                    r = x1 + x2;
                    break;
                case '-':
                    r = x1 - x2;
                    break;
                case '*':
                    r = x1 * x2;
                    break;
                case '/':
                    r = x1 / x2;
                    break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    top = NULL;
    char *postfix = "234*+82/-";
    char *result = inToposfix(postfix);
    cout << "Postfix expression: " << result << endl;
    cout << "Result is " << eval(result) << endl;
    return 0;
}
