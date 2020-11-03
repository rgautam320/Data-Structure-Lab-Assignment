/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

//Queue using Linked List
#include <stdio.h>
#include <stdlib.h>
//Declaring the variables, structures and functions
struct node
{
    int data;
    struct node* link;
};
struct node* top = NULL;
void enqueue();
void dequeue();
void traverse();
//Writing on main function
int main()
{
    int choice;
    while(1)
    {
        printf("Queue Operations : \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
void enqueue()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter an element to insert : ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(top == NULL)
    {
        top = temp;
    }
    else
    {
        struct node* p;
        p = top;
        while(p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}
void dequeue()
{
    struct node* temp;
    printf("%d deleted.\n", top->data);
    if(top == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = top;
        top = temp->link;
        temp->link = NULL;
        free(temp);
    }
}
void traverse()
{
    struct node* temp;
    if(top == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
