#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int>& v);
void counting_sort(vector<int>& v);

int main () {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& x: v) cin >> x;
    
    counting_sort(v);
    print_vector(v);
    
    
    return 0;
}


void print_vector(vector<int>& v) {
    for(int& x: v) cout << x << " ";
    cout << endl;
}

void counting_sort(vector<int>& v) {
    int n = v.size();
    if(n==0) return;

    int max_val = *max_element(v.begin(), v.end());
    vector<int>count(max_val+1, 0), a(n, -1);

    //frequency map
    for(int& x: v) count[x]++;

    //cumulative freq(prefix sum)
    int sum = 0;
    for(int& x: count) {
        sum += x;
        x = sum;
    }
    
    for(int i=n-1; i>=0; i--) {
        count[v[i]]--;
        a[count[v[i]]] = v[i];
    }

    for(int i=0; i<n; i++) {
        v[i] = a[i];
    }
}