#include<iostream>
using namespace std;
struct term
{
    int coeff;
    int exp;
};
struct poly
{
    int num;
    struct term *terms;
};
void create(struct poly *p)
{
    int i;
    cout<<"Enter number of terms";
    cin>>p->num;
    p->terms=new term[p->num];
    cout<<"Enter terms ";
    for(i=0;i<p->num;i++)
    {
        cin>>p->terms[i].coeff>>p->terms[i].exp;
    }
}
void display(struct poly p)
{
    int i;
    for(i=0;i<p.num;i++)
    {
        cout<<p.terms[i].coeff<<" x "<<p.terms[i].exp<<" + ";
       // cout<<endl;
    }
    cout<<endl;

}
struct poly * add(struct poly *p1,struct poly *p2)
{
    int i=0,j=0,k=0;
    struct poly *p3;
    p3=new poly;
    p3->terms=new term[p1->num+p2->num];
    while(i<p1->num && j<p2->num)
    {
        if(p1->terms[i].exp>p2->terms[j].exp)
            p3->terms[k++].exp=p1->terms[i++].exp;
        else  if(p1->terms[i].exp<p2->terms[j].exp)
        {
            p3->terms[k++].exp = p2->terms[j++].exp;
        }
        else
        {
            p3->terms[k].exp=p1->terms[i].exp;
            p3->terms[k++].coeff=p1->terms[i++].coeff+p2->terms[j++].coeff;
        }
    }
    for(;i<p1->num;i++){p3->terms[k++]=p1->terms[i];}
    for(;j<p2->num;j++){p3->terms[k++]=p2->terms[j];}
    p3->num=k;
    return p3;
}
int main()
{
    struct poly x1;
    struct poly x2;
    struct poly *x3;
    create(&x1);
    create(&x2);
    x3= add(&x1,&x2);
    display(*x3);
}
