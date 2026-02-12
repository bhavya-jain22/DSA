#include<stdio.h>

int maze_path(int x, int y) {
    if(x==1 || y==1) return 1;
    return maze_path(x-1, y) + maze_path(x, y-1);
}

int main () {
    int n, m;
    printf("Enter the number of rows and columns of the maze: ");
    scanf("%d %d", &n, &m);
    printf("Total no. of ways to reach (1, 1) is: %d\n", maze_path(n, m));
    return 0;
}