#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;
NODE newnode(int item)
{
    NODE ptr=(NODE)malloc(sizeof(struct node));
    ptr->value=item;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
NODE insertnode (NODE node, int item)
{
    if(node==NULL)
        return newnode(item);
    if(item<node->value)
        node->left=insertnode(node->left,item);
    if(item>node->value)
        node->right=insertnode(node->right,item);
    return node;
}
void Postorder(NODE root)
{
    if(root!=NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d\t",root->value);
    }
}
void Inorder(NODE root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d\t",root->value);
        Inorder(root->right);
    }
}
void Preorder(NODE root)
{
    if(root!=NULL)
    {
        Preorder(root->left);
        printf("%d\t",root->value);
        Preorder(root->right);
    }
}
int main()
{
    NODE root=NULL;
    int value, choice;
    while(1)
    {
        printf("\n---MENU---\n");
        printf("1.Insertion\n");
        printf("2.PreOrder\n");
        printf("3.InOrder\n");
        printf("4.PostOrder\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Insertion\n");
            printf("Enter the value to be inserted : ");
            scanf("%d",&value);
            root=insertnode(root,value);
            printf("\n");
            break;
        case 2:
            printf("PreOrder\n");
            Preorder(root);
            printf("\n");
            break;
        case 3:
            printf("InOrder\n");
            Inorder(root);
            printf("\n");
            break;
        case 4:
            printf("PostOrder\n");
            Postorder(root);
            printf("\n");
            break;
        }
    }
    return 0;
}

