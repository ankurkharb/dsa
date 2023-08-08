#include <iostream>
using namespace std;
struct elem
{
    int i;
    int j;
    int x;
};
struct sparse
{
    int m;
    int n;
    int num;
    struct elem *e;
};
void create(struct sparse *s)
{
    cout<<"Enter dimensions"<<endl;
    cin>>s->m>>s->n;
    cout<<"Enter number of non zero elements"<<endl;
    cin>>s->num;
    s->e=new elem[s->num];
    cout<<"Enter row column and element "<<endl;
    for(int i=0;i<s->num;i++)
    {
            cin>>s->e[i].i>>s->e[i].j>>s->e[i].x;
    }
}
void Display(struct sparse s)
{
    int i,j,k=0;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
                cout<<s.e[k++].x<<" ";
            else
                cout<<"0 ";

        }
        cout<<endl;
    }
}
int main()
{
    struct sparse t;
    create(&t);
    Display(t);
}
