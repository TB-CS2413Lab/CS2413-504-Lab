#include <stdio.h>
#include <stdlib.h>
/*
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
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
struct node *reverseList(struct node *head)
{
    if (head == NULL) 
    {
        printf("List is empty, nothing to reverse.\n");
        return head;
    }
    struct node *prev=NULL,*cur=head, *next=NULL;
    while (cur != NULL) {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}

void main()
{
    struct node *first = inputting_element();
    struct node *p,*q;
    //Printing before reverse
    printf("Printing each element of the linked list before reversing the node:\n");
    printf("[");
    for(p=first;p!=NULL;p=p->next)
        printf("%d ",p->data);
    printf("]\n");

    //Reversing the element
    first = reverseList(first);
    
    //Printing after reverse
    printf("Printing each element of the linked list after reversing the node:\n");
    printf("[");
    for(p=first;p!=NULL;p=p->next)
        printf("%d ",p->data);
    printf("]\n");
    
}