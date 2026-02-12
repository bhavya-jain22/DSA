#include<bits/stdc++.h>
using namespace std;


int main () {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    //selection sort ->
    
    //un-stable (due to swaps, but can be stable if we shift instead of swap)
    //inplace
    int mn_ele, mn_i;
    for(int i=0; i<n; i++) {
        //select min from the remaining array and swap it with the a[i]
        mn_ele = a[i];
        mn_i = i;
        for(int j=i+1; j<n; j++) {
            if(mn_ele>a[j]) {
                mn_ele = a[j];
                mn_i = j;
            }
        }
        swap(a[i], a[mn_i]);
    }

    for(int& x: a) cout << x <<" ";

return 0;
}