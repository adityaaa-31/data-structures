
//Dynamic stack with all operations
struct stack
{
    int info;
    struct stack *next;
};
void init(struct stack **);
void display(struct node **);
void push(struct stack **,int );
struct stack * pop(struct stack **);
void peek(struct stack *);
void isempty(struct stack **);
#include <stdio.h>
#include <stdlib.h>
#include "dystack.h"
int main()
{
    struct stack *s,*e;

    int opt,x,n;

    init(&s);

    do
    {
        printf("1:Push\t2:Pop\t3:Peek\t4:isEmpty\t5:Exit\n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("Enter element to push");
            scanf("%d",&x);
            push(&s,x);
            break;

        case 2:
            e=pop(&s);

            if(e!=NULL)
            {
                free(e);
                peek(s);
            }
            else
                printf("Stack is underflowed\n");
            break;

        case 3:
            peek(s);
            break;

        case 4:
            isempty(s);
            break;
        }
    }
    while(opt!=5);
    return 0;
}
