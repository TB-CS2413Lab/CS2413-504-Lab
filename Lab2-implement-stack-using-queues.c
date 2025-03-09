#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node 
{
    int value;
    struct Node* next;
};

struct Queue 
{
    struct Node* front;
    struct Node* rear;
};

bool isQueueEmpty(struct Queue* queue) 
{
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) 
{
    if (isQueueEmpty(queue)) {
        return -1;
    }

    struct Node* temp = queue->front;
    int value = temp->value;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

int front(struct Queue* queue) 
{
    if (isQueueEmpty(queue)) {
        return -1;  
    }
    return queue->front->value;
}


struct MyStack
{
    struct Queue q1;  
    struct Queue q2;  
};


struct MyStack* myStackCreate() 
{
    struct MyStack* stack = (struct MyStack*)malloc(sizeof(struct MyStack));
    stack->q1.front = NULL;
    stack->q1.rear = NULL;
    stack->q2.front = NULL;
    stack->q2.rear = NULL;
    return stack;
}

void myStackPush(struct MyStack* obj, int x) 
{
    enqueue(&obj->q1, x);  
}


int myStackPop(struct MyStack* obj) 
{
    if (isQueueEmpty(&obj->q1)) {
        return -1;  
    }

    while (obj->q1.front != obj->q1.rear) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    int topElement = dequeue(&obj->q1);

    struct Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    return topElement;
}

int myStackTop(struct MyStack* obj) 
{
    if (isQueueEmpty(&obj->q1)) {
        return -1;  
    }

    while (obj->q1.front != obj->q1.rear) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    int topElement = front(&obj->q1);

    enqueue(&obj->q2, dequeue(&obj->q1));

    struct Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    return topElement;
}

bool myStackEmpty(struct MyStack* obj) 
{
    return isQueueEmpty(&obj->q1);
}


void main() 
{
    struct MyStack* stack = myStackCreate();

    printf("Pushing elements onto the stack:\n");
    myStackPush(stack, 10);
    myStackPush(stack, 20);
    myStackPush(stack, 30);
    myStackPush(stack, 40);
    myStackPush(stack, 50);

    printf("Top element: %d\n", myStackTop(stack));

    printf("\nPopped element: %d\n", myStackPop(stack)); 
    printf("Popped element: %d\n", myStackPop(stack));  
    printf("Popped element: %d\n", myStackPop(stack)); 

    printf("\ntop element after pops: %d\n", myStackTop(stack));  

    printf("\nIs the stack empty?(1=yes, 0=no) %d\n\n", myStackEmpty(stack));  

    printf("Popped element: %d\n", myStackPop(stack));  
    printf("Popped element: %d\n", myStackPop(stack));  

    printf("\nIs the stack empty now?(1=yes, 0=no) %d\n", myStackEmpty(stack)); 

}