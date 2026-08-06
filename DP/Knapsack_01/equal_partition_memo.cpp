#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<vector<int>>& dp, vector<int>& v, int n, int target);

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
    if(target == 0) return true;
    if(n==0) return false;
    if(dp[n][target] != -1) return dp[n][target];
    if(target>=v[n-1]) {
        int take = canPartition(dp, v, n-1, target-v[n-1]);
        int not_take = canPartition(dp, v, n-1, target);
        return dp[n][target] = take || not_take;
    }
    return dp[n][target] = canPartition(dp, v, n-1, target);    
}