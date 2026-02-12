#include<iostream>
#include<vector>
using namespace std;


int main () {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x: a) cin >> x;

    //Insertion sort ->

    //stable
    //inplace
    
    //Imagine this as arranging the cards in hand while playing cards
    for(int i=1; i<n; i++) {
        //take the current element and find its correct position
        int key = a[i];
        int j = i-1;
        //traverse backwards(while k<a[j] and j>=0)
        while(j>=0 && key<a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    for(int& x: a) cout << x << " ";
    cout << endl;

return 0;
}