#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<vector<int>>& dp, vector<int>& a, int n, int target) {
    if(target==0) return dp[n][target] = 1;
    if(n==0 || target<0) return 0;
    if(dp[n][target] != -1) return dp[n][target];
    int take = subsetSum(dp, a, n-1, target-a[n-1]);
    int not_take = subsetSum(dp, a, n-1, target);
    return dp[n][target]  = max(take, not_take);
}

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

    subsetSum(dp, a, n, target);

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=target; j++) cout << dp[i][j] << " ";
        cout << endl;
    }

    if(dp[n][target] == 1) {
        cout << "target is archievable\n";
    }
    else cout << "target is NOT archievable\n";

return 0;
}