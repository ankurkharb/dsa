void remove_duplicate(struct node *p)
{
    p=head;
    struct node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }


}
