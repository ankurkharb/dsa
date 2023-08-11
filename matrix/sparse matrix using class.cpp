#include<iostream>
using namespace std;
class element
{
public:
    int i;
    int j;
    int x;
};
class sparse
{
    int m;
    int n;
    int num;
    element *e;
public:
    sparse(int m,int n,int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        e=new element[this->num];
    }
    ~sparse()
    {
        delete []e;
    }
    void read()
    {
        cout<<"Enter row column and element ";
        for(int i=0;i<num;i++)
        {
            cin>>e[i].i>>e[i].j>>e[i].x;
        }
    }
    void display()
    {
        int i,j,k;
        i=j=k=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==e[k].i && j==e[k].j)
                    cout<<e[k++].x<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};
int main()
{
   // struct sparse s;
    sparse s1(2,2 ,2);
    s1.read();
    s1.display();

}
