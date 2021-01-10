#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int top=-1, stack[MAX];
void push()
{
    int val;

    if(top==MAX-1)
        printf("\nStack is full");
    else
    {
        printf("Enter element to push");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
    }

}
void pop()
{

    if(top==-1)
    {
        printf("\nStack is full");
    }
    else
    {
        printf("\nDeleted element is %d",stack[top]);
        top=top-1;

    }
}
void display()
{
    int i;

    if(top==-1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\n~~Elements in the stack~~");
        for(i=top;i>=0;i--)
            printf("\n%d\n",stack[i]);
    }
}

int main()
{
    int ch;

    printf("\nStack Menu\n1:Push\n2:Pop\n3:Display\n4:Exit");

    while(1)
    {
        printf("\nEnter your choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;
        }
    }

    return 0;
}
