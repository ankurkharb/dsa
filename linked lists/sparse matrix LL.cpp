#include<iostream>
using namespace std;
struct node
{
    int column;
    int data;
    struct node *next;
};
int main()
{
    int m,n,i,j,nz;
    cout<<"Enter number of rows\n ";
    cin>>m;
    cout<<"Enter number of column\n ";
    cin>>n;
    struct node *A[m],*last;
    for(i=0;i<m;i++)
    {
        A[i]=NULL;
        cout<<"Enter no of non zero elements in row "<<i+1<<endl;
        cin>>nz;
        for(j=0;j<nz;j++)
        {
            if(A[i]==NULL)
            {
                A[i]=new node;
                last=A[i];
                cout<<"Enter column and value \n";
                cin>>last->column;
                cin>>last->data;
                last->next=NULL;
            }
            else
            {
                last->next=new node;
                last=last->next;
                cout<<"Enter column and value \n";
                cin>>last->column;
                cin>>last->data;
                last->next=NULL;

            }
        }
    }
    for(i=0;i<m;i++)
    {
        if(A[i]!=NULL)
            last=A[i];
        for(j=0;j<n;j++)
        {
            if(last && last->column==j)
            {
                cout<<last->data;
                last=last->next;
            }
            else
                cout<<" 0 ";
        }
        cout<<endl;
    }

}
