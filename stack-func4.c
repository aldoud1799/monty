#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} stack;

typedef struct queue {
    int data;
    struct queue *next;
} queue;

stack *top = NULL;
queue *front = NULL, *rear = NULL;

void stack_push(int value) {
    stack *new_node = (stack *)malloc(sizeof(stack));
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

int stack_pop() {
    if (top == NULL) {
        printf("Error: Stack is empty\n");
        return 0;
    }
    int value = top->data;
    stack *temp = top;
    top = top->next;
    free(temp);
    return value;
}

void stack_print() {
    stack *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void queue_push(int value) {
    queue *new_node = (queue *)malloc(sizeof(queue));
    new_node->data = value;
    new_node->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}

int queue_pop() {
    if (front == NULL) {
        printf("Error: Queue is empty\n");
        return 0;
    }
    int value = front->data;
    queue *temp = front;
    front = front->next;
    free(temp);
    return value;
}

void queue_print() {
    queue *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void switch_mode() {
    if (top == NULL && front == NULL) {
        printf("Error: Stack and Queue are both empty\n");
        return;
    }
    if (top == NULL) {
        printf("Error: Stack is empty\n");
        return;
    }
    if (front == NULL) {
        printf("Error: Queue is empty\n");
        return;
    }
    stack *temp_stack = top;
    while (temp_stack->next != NULL) {
        temp_stack = temp_stack->next;
    }
    queue *temp_queue = front;
    while (temp_queue->next != NULL) {
        temp_queue = temp_queue->next;
    }
    temp_queue->next = top;
    front = top;
    rear = temp_stack;
    top = NULL;
}

int main() {
    stack_push(1);
    stack_push(2);
    stack_push(3);
