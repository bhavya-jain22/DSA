#include<bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin >> n;
    vector<int> v(n);

    int total = 0;

    for(int i=0; i<n; i++) {
        cin >> v[i];
        total += v[i];
    }

    if(total&1) {
        cout << "false\n";
        return 0;
    }
    
    int target = total/2;
    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

    if(canPartition(dp, v, n, target)) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }

return 0;
}

bool canPartition(vector<vector<int>>& dp, vector<int>& v, int n, int target) {
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=target; j++) {
            if(j==0) {
                dp[i][j] = 1;
                continue;
            }

            if(i==0) {
                dp[i][j] = 0;
                continue;
            }

            if(j>=v[i-1]) {
                dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];            
        }
    }

    return dp[n][target];
}