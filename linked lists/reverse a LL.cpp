void reverse(struct node *p)
{
    struct node *q=NULL;
    struct node *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}
