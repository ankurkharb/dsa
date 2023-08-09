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
struct sparse * add(struct sparse *s1 ,struct sparse *s2)
{
    if(s1->m!=s2->m && s1->n!=s2->n)
    {
        return 0;
    }
    else {

        struct sparse *sum;
        sum = new sparse;
        sum->e = new elem[s1->num + s2->num];
        int i,j,k;
         i=j=k=0;
        while(i<s1->num && j<s2->num)
        {
            if (s1->e[i].i<s2->e[j].i)
                sum->e[k++]=s1->e[i++];
            else  if (s1->e[i].i>s2->e[j].i)
                sum->e[k++]=s2->e[j++];
            else
            {
                if(s1->e[i].j<s2->e[j].j)
                    sum->e[k++]=s1->e[i++];
                else if(s1->e[i].j>s2->e[j].j)
                    sum->e[k++]=s2->e[j++];
                else
                {
                    sum->e[k]=s1->e[i];
                    sum->e[k++].x=s1->e[i++].x+s2->e[j++].x;
                }
            }
        }
        for(;i<s1->num;i++)sum->e[k++]=s1->e[i];
        for(;j<s2->num;j++)sum->e[k++]=s2->e[j];
        sum->m=s1->m;
        sum->n=s1->n;
        sum->num=k;

        return sum;
    }

}
int main()
{
    struct sparse s1;
    struct sparse s2;
    create(&s1);
    create (&s2);
    struct sparse *s3;
    s3=add(&s1,&s2);


    cout<<"First Matrix\n";
    Display(s1);
    printf("Second Matrix\n");
    Display(s2);
    printf("Sum Matrix\n");
    Display(*s3);


    return 0;

}
