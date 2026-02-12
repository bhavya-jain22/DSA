#include<stdio.h>
#include"queue.c"

int main () {
    queue* q;
    push(q, 1);
    push(q, 4);
    push(q, 2);

    print(q);

    pop(q);
    pop(q);

    print(q);

    pop(q);

    if(isEmpty(q)) printf("THE QUEUE IS EMPTY\n");
    else printf("The Queue is not empty\n");
    return 0;
}