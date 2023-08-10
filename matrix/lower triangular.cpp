#include<iostream>
using namespace std;
class lowtri
{
private:
    int n;
    int *A;
public:
    lowtri(int n)
    {
        this->n=n;
        A=new int[n];
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void Display();
    ~lowtri()
    {
        delete []A;
    }
};
void lowtri::set(int i, int j, int x)
{
    if(i==j)
        A[i]=x;
}
int lowtri::get(int i, int j)
{
    if(i==j)
        return A[i];
    else return 0;
}
void lowtri::Display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    class lowtri d(4);
    d.set(1,1,5);
    d.set(2,2 ,10);
    d.set(3,3,15);
    d.set(4,4,20);
    d.Display();

}
