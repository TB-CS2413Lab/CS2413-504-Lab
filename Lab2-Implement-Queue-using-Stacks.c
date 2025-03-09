#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Stack 
{
    struct Node* top;
};

struct QueueUsingStacks 
{
    struct Stack* stack1;
    struct Stack* stack2;
};

struct Stack* createStack() 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    
    return stack;
}

void push(struct Stack* stack, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) 
{
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return -1; 
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    
    return data;
}

int peek(struct Stack* stack)
{
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return -1; 
    }
    return stack->top->data;
}

int isEmpty(struct Stack* stack) 
{
    return stack->top == NULL;
}



struct QueueUsingStacks* createQueue() 
{
    struct QueueUsingStacks* queue = (struct QueueUsingStacks*)malloc(sizeof(struct QueueUsingStacks));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}

void queuePush(struct QueueUsingStacks* queue, int data) 
{
    push(queue->stack1, data);
}

int queuePop(struct QueueUsingStacks* queue) 
{
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            int data = pop(queue->stack1);
            push(queue->stack2, data);
        }
    }
    if (isEmpty(queue->stack2)) {
        printf("Queue underflow\n");
        return -1; 
    }
    return pop(queue->stack2);
}
int queuePeek(struct QueueUsingStacks* queue) 
{
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            int data = pop(queue->stack1);
            push(queue->stack2, data);
        }
    }
    if (isEmpty(queue->stack2)) {
        return -1; 
    }
    return peek(queue->stack2);
}

void displayQueue(struct QueueUsingStacks* queue) 
{
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue is empty\n");
        return;
    }

    struct Stack* tempStack = createStack();
    while (!isEmpty(queue->stack1)) {
        int data = pop(queue->stack1);
        push(tempStack, data);
    }
    while (!isEmpty(tempStack)) {
        int data = pop(tempStack);
        printf("%d ", data);
        push(queue->stack1, data); 
    }

    struct Stack* tempStack2 = createStack();
    while (!isEmpty(queue->stack2)) {
        int data = pop(queue->stack2);
        printf("%d ", data);
        push(tempStack2, data); 
    }
    while (!isEmpty(tempStack2)) {
        int data = pop(tempStack2);
        push(queue->stack2, data);
    }
    printf("\n");
}

int main() 
{
    struct QueueUsingStacks* queue = createQueue();

    queuePush(queue, 1);
    queuePush(queue, 2);
    queuePush(queue, 3);
    queuePush(queue, 4);
    queuePush(queue, 5);

    printf("Queue after enqueue (queuePush for this one) operations: ");
    displayQueue(queue);

    printf("Queue Peek: %d\n", queuePeek(queue));

    printf("Dequeue: %d\n", queuePop(queue));
    printf("Dequeue: %d\n", queuePop(queue));

    printf("Queue after dequeue (queuePop in this) operations: ");
    displayQueue(queue);
}