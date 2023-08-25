void display(struct node *p)
{
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void rdisplay(struct node *p)
{
    if(p!=NULL) {
        cout <<p->data<<" ";
        display(p->next);
    }

}
