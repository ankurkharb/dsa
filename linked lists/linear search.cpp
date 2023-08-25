node * linearsearch(struct node *p,int key)
{
    while(p!=0)
    {
        if(key==p->data)
            return p;
        else
        {
            p=p->next;
        }
    }
    return NULL;
}
