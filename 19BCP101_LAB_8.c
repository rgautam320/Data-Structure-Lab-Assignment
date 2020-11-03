/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

//Implementation of Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
//Declaration of variables and structures
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node * root = NULL;

void insert(int ele);
void traverse_inorder(struct node* root);
void traverse_preorder(struct node* root);
void traverse_postorder(struct node* root);
int count_leaves(struct node* root);
int height(struct node* root);
int main()
{
    while(1)
    {
        int choice, ele;
        printf("<--- Operations on BST --->\n");
        printf("1. Insertion\n");
        printf("2. In order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post order Traversal\n");
        printf("5. Count Leaves\n");
        printf("6. Height\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter an element to insert : ");
            scanf("%d", &ele);
            printf("%d successfully inserted.\n\n", ele);
            insert(ele);
            break;
        case 2:
            traverse_inorder(root);
            printf("\n\n");
            break;
        case 3:
            traverse_preorder(root);
            printf("\n\n");
            break;
        case 4:
            traverse_postorder(root);
            printf("\n\n");
            break;
        case 5:
            printf("Total Leaf Count : %d\n\n", count_leaves(root));
            break;
        case 6:
            printf("Maximum Height : %d\n\n", height(root));
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n\n");
        }
    }
    return 0;
}
//Function to insert an element to the tree
void insert(int ele)
{
    struct node* temp, *p, *q;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        q = root;
        while(1)
        {
            p = q;
            if(temp->data < p->data)
            {
                q = q->left;
                if(q == NULL)
                {
                    p->left = temp;
                    return;
                }
            }
            else
            {
                q = q->right;
                if(q == NULL)
                {
                    p->right = temp;
                    return;
                }
            }
        }
    }
}
//To traverse in different manners
void traverse_inorder(struct node* root)
{
    if(root != NULL)
    {
        traverse_inorder(root->left);
        printf("%d\t", root->data);
        traverse_inorder(root->right);
    }
}
void traverse_preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d\t", root->data);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}
void traverse_postorder(struct node* root)
{
    if(root != NULL)
    {
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("%d\t", root->data);
    }
}
// To find the total number of leaf nodes
int count_leaves(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return count_leaves(root->left)+count_leaves(root->right);
    }
}
// To find the maximum height of the tree
int height(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int c1 = height(root->left);
        int c2 = height(root->right);
        if(c1>c2)
        {
            return c1+1;
        }
        else
        {
            return c2+1;
        }
    }
}
