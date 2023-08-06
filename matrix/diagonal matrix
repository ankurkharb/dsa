#include<iostream >
using namespace std;
struct matrix
{
    int A[20];
    int n;
};
void set(matrix *m,int i,int j,int x)
{
    if(i==j)
    {
        m->A[i-1]=x;
    }
}
int get(matrix m,int i,int j)
{
    if(i==j)
    {
        return m.A[i-1];
    }
    else return 0;
}
void Display(matrix m)
{
    int i,j;
    for(i=0;i<m.n;i++)
    {
        for(j=0;j<m.n;j++)
        {
            if(i==j)
                cout<<m.A[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    struct matrix m;
    m.n=3;
    set(&m,1,1,5);
    set(&m,2,2,10);
    set(&m,3,3,15);
    Display(m);
}
