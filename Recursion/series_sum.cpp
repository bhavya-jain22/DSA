#include<bits/stdc++.h>
using namespace std;

// 1 + 2 + 3 +....+ n
int sum (int n) {
    if(n<=0) return 0;
    return n + sum(n-1);
}

int sum2 (int n) {
    if(n==1) return 1;
    return n + sum2(n-2);
}

int square(int n) {
    if(n == 1) return 1;
    return sum2(2*n-1) + square(n-1);
}

int main () {
    
return 0;
}