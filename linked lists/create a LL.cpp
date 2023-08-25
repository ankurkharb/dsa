struct node
{
    int data;
    struct node *next;
}*head,*second,*third;
void ll(struct node *p)
{
    while(p!=NULL)
    {
        cout << "Element is : " << p->data<<endl;
        p = p->next;
    }

}
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
