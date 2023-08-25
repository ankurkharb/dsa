int issorted(struct node *p)
{
    int x=INT_MIN;
    while(p!=NULL)
    {
        if(x>p->data)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
