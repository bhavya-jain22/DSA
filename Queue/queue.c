#include<stdio.h>
#include<stdlib.h>
//queue using singly linked list (SLL)

typedef struct node {
    int val;
    struct node* next;
}node;

typedef struct queue {
    node* front;
    node* rear;
}queue;

void init(queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(queue* q) {
    if(q->front == NULL) return 1;
    else return 0;
}

void push(queue* q, int v) {
    node* temp = (node*) malloc (sizeof(node));
    temp->next = NULL;
    temp->val = v;

    if(q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void pop(queue* q) {
    if(q->front == NULL) {
        printf("Queue Underflow\\n");
        return;
    }
    node* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL) q->rear = NULL;
    free(temp);
}

void print(queue* q) {
    if(q->front == NULL) {
        printf("Queue Empty\n");
        return;
    }
    node* traverse = q->front;
    while(traverse!= NULL) {
        printf("%d ", traverse->val);
        traverse = traverse->next;
    }
    printf("\n");
}