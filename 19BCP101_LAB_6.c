/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

//Doubly Linked List Implementation
#include <stdio.h>
#include <stdlib.h>
//Declaring the structures and functions
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int len;
struct node * root = NULL;
void addend(void);
void addbegin(void);
void addafter(void);
void display(void);
void reverse(void);
void del(void);
void delvalue(int value);
void dellist(void);

int search(int value);
int length(void);
//Writing inside the main function
int main()
{
    int choice, value;
    while(1)
    {
        printf("Double Linked List Operations : \n");
        printf("1. Append\n");
        printf("2. Add at Begin\n");
        printf("3. Add at After\n");
        printf("4. Display\n");
        printf("5. Reverse\n");
        printf("6. Delete\n");
        printf("7. Delete Value\n");
        printf("8. Delete List\n");
        printf("9. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            addend();
            break;
        case 2:
            addbegin();
            break;
        case 3:
            addafter();
            break;
        case 4:
            display();
            break;
        case 5:
            reverse();
            break;
        case 6:
            del();
            break;
        case 7:
            printf("Enter the value to delete : ");
            scanf("%d", &value);
            delvalue(value);
            printf("\n\n");
            break;
        case 8:
            dellist();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n\n");
        }
    }
    return 0;
}
//This will add element at the end
void addend()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter an element to append : ");
    scanf("%d", &temp->data);
    printf("%d inserted.\n\n", temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node* p = root;
        while(p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
}
//This will add the element at the beginning
void addbegin()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter an element to insert : ");
    scanf("%d", &temp->data);
    printf("%d inserted.\n\n", temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->right = root;
        root->left = temp;
        root = temp;
    }
}
//This will add the element at the the certain node
void addafter()
{
    struct node* temp, *p = root, *q;
    int key, i = 1;
    printf("Enter the location where you want to insert : ");
    scanf("%d", &key);
    if(key > len)
    {
        printf("Unable to insert \n\n");
    }
    else
    {
        while(i < key)
        {
            p = p->right;
            i++;
        }
        q = p->right;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter an element to insert : ");
        scanf("%d", &temp->data);
        printf("%d inserted\n\n", temp->data);
        temp->left = NULL;
        temp->right = NULL;
        temp->right = q;
        q->left = temp;
        p->right = temp;
        temp->left = p;
    }
}

//This will traverse the list when it is called
void display()
{
    struct node * temp = root;
    if(root == NULL)
    {
        printf("List is Empty\n\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d --> ", temp->data);
            temp = temp->right;
        }
        printf("\n\n");
    }
}
//This will reverse and traverse the list when it is called
void reverse()
{
    struct node* temp = root;
    if(root == NULL)
    {
        printf("List is Empty\n\n");
    }
    else
    {
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        while(temp != NULL)
        {
            printf("%d --> ", temp->data);
            temp = temp->left;
        }
        printf("\n\n");
    }
}

//This will delete the element of the list at the specified position
void del()
{
    struct node* temp;
    int key, i = 1;
    printf("Enter the location of element to delete : ");
    scanf("%d", &key);
    if(key > length())
    {
        printf("Invalid Location to perform delete\n\n");
    }
    else if(key == 1)
    {
        temp = root;
        root = temp->right;
        temp->left = NULL;
        free(temp);
    }
    else if(key == length())
    {
        struct node * temp, *p;
        p = root;
        while(p->right != NULL)
        {
            p = p->right;
        }
        temp = p->left;
        temp->right = NULL;
        free(p);
    }
    else
    {
        struct node *p, *q;
        temp = root;
        while(i < key)
        {
            temp = temp->right;
            i++;
        }
        q = temp->right;
        p = temp->left;
        p->right = q;
        q->left = p;
        free(temp);
    }
}
//This function delete the given value from the list
void delvalue(int value)
{
    struct node* temp = root, *p, *q;
    //q = root->right;
    if(root->data == value)
    {
        root = temp->right;
        free(temp);
    }
    else if(search(value) == 1)
    {
        while(temp->data != value)
        {
            temp = temp->right;
        }
        q = temp->right;
        p = temp->left;
        if(temp->right != NULL)
        {
            p->right = q;
            q->left = p;
            free(temp);
        }
        else
        {
            p->right = NULL;
            free(temp);
        }
    }
    else
    {
        printf("Value not found in the list.\n\n");
    }
}
//This function deletes the whole list
void dellist()
{
    struct node *temp = root, *p;
    while(temp != NULL)
    {
        p = temp->right;
        free(temp);
        temp = p;
    }
    printf("All the elements in the list deleted successfully.\n\n");
    root = NULL;
}

//This calculates the length of the list
int length()
{
    struct node* temp = root;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}
//This function search the value in the list
int search(int value)
{
    struct node *p = root;
    while(p != NULL)
    {
        if(p->data == value)
        {
            return 1;
        }
        else
        {
            p = p->right;
        }
    }
    return 0;
}


