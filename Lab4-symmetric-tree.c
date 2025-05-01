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

struct queueNode 
{
    struct node* treeNode;
    struct queueNode* next;
};

struct queue 
{
    struct queueNode *front, *rear;
};

struct queue* createQueue() 
{
    struct queue* q = malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue* q, struct node* treeNode) 
{
    struct queueNode* temp = malloc(sizeof(struct queueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) 
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct node* dequeue(struct queue* q) 
{
    if (q->front == NULL)
        return NULL;
    struct queueNode* temp = q->front;
    struct node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return treeNode;
}

int isQueueEmpty(struct queue* q) 
{
    return q->front == NULL;
}

struct tree* createtree() 
{
    struct tree* tree = (struct tree*)malloc(sizeof(struct tree));
    tree->root = NULL;
    return tree;
}

void addToTree(struct tree* tree, int n) 
{
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node == NULL) 
    {
        printf("Error: malloc failed \n");
        exit(EXIT_FAILURE);
    }
    new_node->data = n;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    struct queue* q = createQueue();
    enqueue(q, tree->root);

    while (!isQueueEmpty(q)) 
    {
        struct node* current = dequeue(q);
        if (current->left == NULL) 
        {
            current->left = new_node;
            break;
        } else {
            enqueue(q, current->left);
        }

        if (current->right == NULL) 
        {
            current->right = new_node;
            break;
        } 
        else 
        {
            enqueue(q, current->right);
        }
    }
    free(q);
}

void inOrder(struct node* root) 
{
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isMirror(struct node* t1, struct node* t2) 
{
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;
    return (t1->data == t2->data) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

int isSymmetric(struct tree* tree) 
{
    if (tree->root == NULL)
        return 1;
    return isMirror(tree->root->left, tree->root->right);
}

int main() 
{
    struct tree* my_tree = createtree();
    addToTree(my_tree, 1);
    addToTree(my_tree, 2);
    addToTree(my_tree, 2);
    addToTree(my_tree, 3);
    addToTree(my_tree, 4);
    addToTree(my_tree, 4);
    addToTree(my_tree, 3);

    printf("Inorder traversal: ");
    inOrder(my_tree->root);
    printf("\n");

    if (isSymmetric(my_tree))
    printf("The tree is symmetric.\n");
    else
    printf("The tree is not symmetric.\n\n");

    struct tree* my_tree1 = createtree();
    addToTree(my_tree1, 1);
    addToTree(my_tree1, 2);

    printf("Inorder traversal: ");
    inOrder(my_tree1->root);
    printf("\n");

    if (isSymmetric(my_tree1))
    printf("The tree is symmetric.\n");
    else
    printf("The tree is not symmetric.\n");

    return 0;
}