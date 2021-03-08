#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

static void reverse(struct node **head_ref)
{
    struct node *prev = NULL;
    struct node *current = *head_ref;
    struct node *next = NULL;


    while(current!=NULL)
    {
        next = current -> next;

        current -> next = prev;

        prev = current;

        current = next;
    }

    *head_ref = prev;

}
void push(struct node **head_ref,int newdata)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));

    newnode->data = newdata;
    newnode->next = (*head_ref);
    (*head_ref) = newnode;

}

void printlist(struct node *head)
{
    struct node *tmp = head;

    while(tmp != NULL)
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }
}
int main()
{
    struct node *head=NULL;

    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);

    printf("Given list\n");
    printlist(head);

    reverse(&head);

    printf("Reversed list\n");
    printlist(head);

    return 0;
}
