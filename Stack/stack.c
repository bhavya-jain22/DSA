#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    int* arr;
    int top;
    int size;
}stack;

int isEmpty(stack* s) {
    return (*s).top == -1;
}

int isFull(stack* s) {
    return (*s).top == (*s).size-1;
}

void push(stack* s, int val) {
    if(!isFull(s)) {
        (*s).top++;
        (*s).arr[(*s).top] = val;
    }
    else printf("Stack Overflow\n");
    return;
}

void pop(stack* s) {
    if(!isEmpty(s)) {
        (*s).top--;
    }
    else printf("Stack Underflow\n");
}


int top(stack* s) {
    if(!isEmpty(s)) {
        return (*s).arr[(*s).top];
    }
    else {
        printf("Stack is Empty\n");
        return -1;
    }
}


stack* initialise (int n) {
    stack* st = (stack*) malloc (sizeof(stack));
    st->arr = (int*) malloc(sizeof(int)*n);
    if(st->arr == NULL) {
        printf("Memory not allocated\n");
    }
    st->size = n;
    st->top = -1;
    return st;
}