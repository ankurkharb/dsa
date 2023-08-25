int isloop(struct node *f)
{
    struct node *p;
    struct node *q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    }while(p && q && p!=q);
    return p==q? true:false;
}
