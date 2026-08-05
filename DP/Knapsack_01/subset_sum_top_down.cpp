#include<bits/stdc++.h>
using namespace std;


int main () {
    int n;
    cout << "n: ";
    cin >> n;
    cout << "Enter elements: ";
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=target; j++) {

            if(j == 0) {
                dp[i][j] = 1;
                cout << dp[i][j] << " ";
                continue;
            }
            
            if(i==0) {
                dp[i][j] = 0;
                cout << dp[i][j] << " ";
                continue;
            }
            
            
            if(j>=a[i-1]) {
                dp[i][j] = max(dp[i-1][j-a[i-1]], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];            
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    if(dp[n][target]==1) {
        cout << "target is archievable\n";
    }
    else cout << "target is UN archievable\n";



return 0;
}