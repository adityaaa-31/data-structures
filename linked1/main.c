#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create()
{
    int n;

    struct node *tmp;

    tmp = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data");
    scanf("%d",&n);

    if(head == NULL)
    {
        head = tmp;
        tmp -> data = n;
        tmp -> next = NULL;
    }
    tmp -> data = n;
    tmp -> next = head;
    tmp = head;

}
void display()
{
    struct node *tmp;

    tmp = head;

    while(tmp != NULL)
        {
        printf("%d\t",tmp->data);
        tmp=tmp->next;
        }
}

int main()
{

    int ch;


    head = (struct node *)malloc(sizeof(struct node));


    printf("Enter choice :");


    while(1)
    {

        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        //case 3:
          //  insert();
           // break;

        case 3:
            exit(0);
    }
    }
    return 0;

}
