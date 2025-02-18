#include <stdio.h>
#include <stdlib.h>
/*
Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
*/

struct node{
    int data;
    struct node* next;
};
struct node *add_to_list(struct node *head, int n)
{
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Error: malloc failed \n");
        exit(EXIT_FAILURE);
    }
    new_node->data = n;
    new_node->next = head;
    return new_node;
}
struct node *inputting_element(void)
{
    struct node *first=NULL;
    int data;
    printf("Please give inputs for the linked list (enter 0 when done)\n");
    for(;;)
    {
        scanf("%d",&data);
        if(data==0)
            break;
        first=add_to_list(first, data);
    }
    return first;
};
struct node *removeElements(struct node *head, int val)
{
    struct node *prev = NULL, *cur = head;
    int count = 0;
    while (cur != NULL)
    {
        if (cur->data == val)
        {
            if (prev == NULL)
            {
                head = cur->next;
            }
            else
            {
                prev->next = cur->next;  
            }
            struct node *temp = cur;
            cur = cur->next;
            free(temp);
            count++;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    if(count==0)
    {
        printf("Element to be deleted not found\n");
    }
    return head;
}

void main()
{
    struct node *first = inputting_element();
    struct node *p,*q;
    //Printing before deleting
    printf("Printing each element of the linked list before deleting the node:\n");
    printf("[");
    for(p=first;p!=NULL;p=p->next)
        printf("%d ",p->data);
    printf("]\n");

    //Deleting the element
    int d;
    printf("\nGive input for element you want to delete\n");
    scanf("%d",&d);
    first=removeElements(first, d);
    
    //Printing after deleting
    printf("Printing each element of the linked list after deleting the node:\n");
    printf("[");
    for(p=first;p!=NULL;p=p->next)
        printf("%d ",p->data);
    printf("]");
    
}