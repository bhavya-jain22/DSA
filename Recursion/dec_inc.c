#include<stdio.h>

void print_dec(int n) {
    if(n<=0) return;
    printf("%d ", n);
    print_dec(n-1);
}

void print_inc(int n) {
    if(n<=0) return;
    print_inc(n-1);
    printf("%d ", n);
}


int main () {
    print_dec(10);
    printf("\n");
    print_inc(10);
    printf("\n");
    return 0;
}