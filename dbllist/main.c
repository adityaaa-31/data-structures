#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head = NULL;

void insbeg()
{

    int x;

    struct node *newnode,*tmp = head;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data :");
    scanf("%d",&x);

    newnode -> data = x;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    if(head == NULL)
    {
        head = newnode = tmp;
    }
    else
    {
         tmp -> next =  newnode;
         tmp -> prev = head;
         tmp = newnode;
    }

}
void insend()
{
    struct node *tmp,*newnode;
    int data;

    printf("Enter the data");
    scanf("%d",&data);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    if(head == NULL)
        newnode = head;
    else
    {
        tmp =  head;

        while(tmp -> next != NULL)
            tmp = tmp -> next;

        tmp -> next = newnode;
        newnode -> prev = tmp;
    }


}
void display()
{
    struct node *tmp;

    tmp = (struct node *)malloc(sizeof(struct node));


    if(tmp == NULL)
        printf("List empty\n");
    else
    {
         tmp = head;
        while(tmp != NULL)
        {
            printf("%d" , tmp -> data);
            tmp = tmp -> next;
        }
    }
}

int main()
{
    int n;

    head = (struct node *)malloc(sizeof(struct node));

    while(1)
    {

    printf("Enter choice ");
    scanf("%d",&n);

    switch(n)
    {
        case 1:
            insbeg();
            break;

        case 2:
            display();
            break;

        case 3:
            insend();
            break;

        case 7:
            exit(0);
    }
    }
    return 0;
}
