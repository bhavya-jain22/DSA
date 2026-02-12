#include <iostream>
using namespace std;


void reverse_arr(int * arr, int i, int n) {
    if (i>=n) return;
    swap(arr[i], arr[n]);
    i++;
    n--;
    reverse_arr(arr, i, n);
}

int main () {
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    // for (int i=0; i<10; i++) {
    //     cin >> a[i];
    // }
    reverse_arr(a, 0, 9);
    for(int x: a) cout << x << " ";
    cout << endl;
    return 0;
}