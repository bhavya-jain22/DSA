#include<stdio.h>

void tower_of_hanoi(int n, char s, char h, char d) {
    if(n==0) return;
    tower_of_hanoi(n-1, s, d, h);
    printf("%c -> %c\n", s, d);
    tower_of_hanoi(n-1, h, s, d);
}

int main() {
    int n;
    // char s, h, d;
    printf("Enter the no. of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}