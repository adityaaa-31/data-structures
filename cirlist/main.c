#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
}*last;
int data,pos;
void create()
{
    struct node *tmp;

    printf("\nEnter element");
    scanf("%d",&data);

    tmp=(struct node *)malloc(sizeof(struct node));

    tmp->info=data;
    if(last==NULL)
    {
        last=tmp;
        tmp->link=last;
    }
    else
    {
        tmp->link=last->link;
        last->link=tmp;
        last=tmp;
    }

}

void insertbeg()
{
    struct node *tmp;
    printf("\nEnter the element: ");
    scanf("%d",&data);

    tmp=(struct node *)malloc(sizeof(struct node));

    tmp->info=data;
    tmp->link=last->link;

    last->link=tmp;
    display();

}

void insertend()
{
    struct node *tmp;

    printf("\nEnter element");
    scanf("%d",&data);

    tmp=(struct node *)malloc(sizeof(struct node));

    tmp->info=data;
    tmp->link=last->link;
    last->link=tmp;
    last=tmp;
    display();

}

void insertpos()
{
    struct node *tmp,*q;
    int i;

    printf("\nEnter elements");
    scanf("%d",&data);

    printf("\nEnter pos");
    scanf("%d",&pos);

    q=last->link;

    for(i=0;i<pos;i++)
    {
        q=q->link;
        if(q==last->link)
        {
            printf("\nThere are less elements");
            return;
        }

    }
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->link=q->link;
    tmp->info=data;
    q->link=tmp;

    if(q==last)
    {
        last=tmp;
    }

    display();

}

void delbeg()
{
    struct node *q;

    if(last->link==last)
    {
        last==NULL;
        free(last);

        printf("\nList is empty");
        return;
    }
    if(last==NULL)
    {
        printf("\nEmpty");
    }

    q=last->link;

    last->link=q->link;

    free(q);

    printf("\nDeleted");

    display();
    return;
}

void delend()
{
    struct node *q;

    q=last->link;

    if(last==NULL)
    {
        printf("List empty");
    }

    if(last->link==last)
    {
        q=q->link;
    }

    q->link=last->link;
    free(last);
    last=q;
    printf("\nDeleted");

    display();
    return;
}


void delpos()
{
    struct node *tmp,*q;
    int i;

    printf("\nEnter the index:");
    scanf("%d",&pos);

    q=last->link;

    for(i=0;i<pos;i++)
    {
        q=q->link;
        if(q==last)
        {
            printf("\nLess elements");
            return;
        }
    }

    if(q->link==last)
    {
        q->link=last->link;
        free(last);

        last=q;

        display();
        return;
    }

    tmp=q->link;
    q->link=tmp->link;
    free(tmp);

    display();
    return;
}

void display()
{
    struct node *q;

    if(last==NULL)
    {
        printf("\nEmpty");
        return;
    }

    printf("\n**ELEMENTS**");

    q=last->link;
    while(q!=last)
    {
        printf("\n%d\t",q->info);
        q=q->link;
    }
    printf("%d\t",last->info);
}

void search()
{
    struct node *tmp;

    int i=0,item;

    printf("\nEnter the element:");
    scanf("%d",&item);

    tmp=last->link;
    while(tmp!=NULL)
    {
        if(tmp->info==item)
        {
            printf("Found at %d",i);
            return;
        }
        tmp=tmp->link;
        i++;
    }

    if(last->info==item)
    {
        printf("Found at %d",i);
    }
    else
        printf("\nNot found");
}
int main()
{

    int ch;
    last=NULL;

    printf("\n1:Create 2:Insert beg 3:Insert at end  4:Insert after pos 5:del beg 6:Del at end 7:Del after pos 8:Search 9:Display 10:Exit");

    while(1)
    {
        printf("\nEnter your choice");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            create();
            break;

        case 2:
            insertbeg();
            break;

        case 3:
            insertend();
            break;

        case 4:
            insertpos();
            break;

        case 5:
            delbeg();
            break;

        case 6:
            delend();
            break;

        case 7:
            delpos();
            break;

        case 8:
            search();
            break;

        case 9:
            display();
            break;

        case 10:
            exit(0);

        default:
            printf("Enter a no within the range");

        }
    }
    return 0;
}
