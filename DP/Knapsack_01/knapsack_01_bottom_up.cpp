#include<bits/stdc++.h>
using namespace std;


int main () {

    int n, w;
    cout << "Enter the number of items & the capacity of the bag: ";
    cin >> n >> w;
    vector<int> wt(n), val(n);
    cout << "Enter the weight and value of the items\n";
    for(int i=0; i<n; i++) {
        cin >> wt[i] >> val[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<w+1; j++) {
            // base case -> initialization
            if(i==0 || j==0) {
                dp[i][j] = 0;
                continue;
            }
            
            if(wt[i-1]<=j) {
                int take = val[i-1] + dp[i-1][j-wt[i-1]];
                int not_take = dp[i-1][j];
                dp[i][j] = max(take, not_take);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

return 0;
}
