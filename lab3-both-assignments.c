#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct tree
{
    struct node* root;
};

struct tree* createtree() 
{
    struct tree* tree = (struct tree*)malloc(sizeof(struct tree));
    tree->root=NULL;
    return tree;
}

struct node *addToTree(struct tree *tree, int n)
{
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Error: malloc failed \n");
        exit(EXIT_FAILURE);
    }
    new_node->data = n;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) 
    {
        tree->root = new_node;
        return new_node;
    }

    struct node* temp = tree->root;
    struct node* parent = NULL;

    while (temp != NULL) 
    {
        parent = temp; 
        if (n < temp->data) 
        {
            temp = temp->left;  
        } 
        else 
        {
            temp = temp->right; 
        }
    }

    if (n < parent->data) 
    {
        parent->left = new_node;  
    } 
    else 
    {
        parent->right = new_node; 
    }
    return new_node;
}
struct node* findLargestNode(struct node* root) 
{
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
struct node *deleteFromTree(struct node* root, int n)
{
    if (n < root->data) 
    {
        root->left = deleteFromTree(root->left, n);
    }
    else if (n > root->data) 
    {
        root->right = deleteFromTree(root->right, n);
    }
    else 
    {
        if (root->left != NULL && root->right != NULL) 
        {
            struct node* largestNodeLeft = findLargestNode(root->left);
            root->data = largestNodeLeft->data;
            root->left = deleteFromTree(root->left, largestNodeLeft->data); // Delete the largest node in the left subtree
        }
        else 
        {
            struct node* temp = root;
            if (root->left == NULL) 
            {
                root = root->right; 
            } else if (root->right == NULL) 
            {
                root = root->left;
            }
            free(temp); 
        }
    }

    return root;

}
void preOrder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node* root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
void inOrder(struct node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
int main() 
{
    struct tree* my_tree = createtree();
    addToTree(my_tree, 45);
    addToTree(my_tree, 39);
    addToTree(my_tree, 12);
    addToTree(my_tree, 10);
    addToTree(my_tree, 34);
    addToTree(my_tree, 32);
    addToTree(my_tree, 56);
    addToTree(my_tree, 54);
    addToTree(my_tree, 78);
    
    
    printf("Pre: ");
    preOrder(my_tree->root);
    printf("\nIn: ");
    inOrder(my_tree->root);
    printf("\nPost: ");
    postOrder(my_tree->root);

    
}