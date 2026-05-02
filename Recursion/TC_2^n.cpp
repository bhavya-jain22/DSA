#include<bits/stdc++.h>
using namespace std;
// just have a look at this problem (like subset sum)
// dry run on your own
int  calls= 0, iterations = 0;

void func(int i, int n) {
    calls++;
    cout << calls;
    cout << "\t("<<i<<","<<n<<")\n";
    for(int j=i; j<=n; j++) {
        iterations++;
        func(j+1, n);
    }
}

// TC -> 
// T(n) = T(n-1) + T(n-2) + T(n-3) + ... + T(0) + 1
// => 2^n

int main () {
    int n;
    cout <<"Enter n: ";
    cin >> n;
    func(1, n);
    cout << "\nFunction is called '" << calls << "' times\n";
    cout << "Iterations: " << iterations << endl;
return 0;
}