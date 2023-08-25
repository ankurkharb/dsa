void insert(struct node *p,int index,int x)
{
    struct node*t;
    if(index<0 ||index >count(head))
        return;
    t=new node;
    t->data=x;
    if(index==0)
    {
        t->next=head;
        head=t;
    }
    else
    {
        int i;
        for(i=0;i<index-1;i++)
        {
            p = p->next;
        }
        t->next=p->next;
        p->next=t;

    }
}
