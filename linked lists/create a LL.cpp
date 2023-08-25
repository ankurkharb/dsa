void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    head=new node;
    head->data=A[0];
    head->next=NULL;
    last=head;
    for(i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}
