int sum(struct node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
void max(struct node *p)
{
    int max=INT_MIN;
    while(p!=0)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
    cout<<"Maximum element is "<<max;
}
