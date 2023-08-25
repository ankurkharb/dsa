int Delete(struct node *p,int pos)
{
    struct node* q;
    int x;
    if(pos<1 || pos> count(p))
        return -1;
    if(pos==1)
    {
        x=head->data;
        p=head;
        head=head->next;
        delete p;
    }
    else
    {
        int i;
        p=head;
        q=NULL;
        for(i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        if(p) {
            q->next = p->next;
            x = p->data;
            delete p;
        }
        return x;
    }
}
