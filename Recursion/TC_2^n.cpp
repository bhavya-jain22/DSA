#include<bits/stdc++.h>
using namespace std;
// just have a look at this problem (subset sum like)
// dry run on your own
int cnt = 0;

void func(int i, int n) {
    cnt++;
    cout << cnt;
    cout << "\t("<<i<<","<<n<<")\n";
    for(int j=i; j<=n; j++) {
        func(j+1, n);
    }
}

int main () {
    int n;
    cout <<"Enter n: ";
    cin >> n;
    func(1, n);
    cout << "\nFunction is called '" << cnt << "' times\n";
return 0;
}