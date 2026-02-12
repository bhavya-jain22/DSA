#include<bits/stdc++.h>
using namespace std;


int main () {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x: a) cin >> x;

    //Normal Bubble sort ->

    //stable
    //inplace

    //It works on swapping two consecutive elements
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(a[j]>a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }

    //Modified Bubble sort->
    for(int i=0; i<n; i++) {
        bool swapped = false;
        for(int j=0; j<n-i-1; j++) {
            if(a[j]>a[j+1]) {
                swap(a[j], a[j+1]);
                swapped = true;
            }
        }
        //if no element is swapped, that means we have sorted the array and no more need to check
        if(!swapped) break;
    }

    for(int& x: a) cout << x << " ";
    cout << endl;

return 0;
}