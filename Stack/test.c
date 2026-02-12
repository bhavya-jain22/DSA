#include"stack.c"

int main () {
    int n;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &n);
    stack* st = initialise(n);
    push(st, 1);
    push(st, 2);
    while(!isEmpty(st)) {
        printf("%d\n", top(st));
        pop(st);
    }
return 0;
}