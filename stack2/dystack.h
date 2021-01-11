void init(struct stack **s)
{
    *s=NULL;
}
void push(struct stack **s,int x)
{
    struct stack *p;
    p=(struct stack *)malloc(sizeof(struct stack));

    p->info=x;
    p->next=NULL;

    if(*s==NULL)
    {
        *s=p;
    }
    else
    {
        p->next=*s;
        *s=p;
    }
}
display(struct stack **s)
{
    struct stack *p;

    if(*s==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        p=*s;
        while(p!=NULL)
        {
            printf("%d\t",p->info);
            p=p->next;
        }

    }
}
struct stack * pop(struct stack **s)
{
    struct stack *p;

    if(*s==NULL)
        return NULL;
    else
    {
        p=*s;
        *s=(*s)->next;
        p->next=NULL;
        return p;
    }
}
void peek(struct stack *s)
{
    if(s==NULL)
        printf("\nList is empty\n");
    else
        printf("\n%d\n",s->info);
}
void isempty(struct stack **s)
{
    if(s==NULL)
        printf("\nList is empty\n");
    else
        printf("\nList is not empty\n");
}
