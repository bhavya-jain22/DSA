#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<vector<int>>& dp, vector<int>& weight, vector<int>& value, int w, int n);


int main () {

    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    vector<int> weight(n, 0), value(n, 0);
    cout << "Enter the wt and val of the items: " << endl;
    for(int i=0; i<n; i++) {
        cin >> weight[i] >> value[i];
    }
    cout << "Enter the capacity of the Knapsack: ";
    cin >> w;

    cout << knapsack(dp, weight, value, w, n-1);
    
    return 0;
}

int knapsack(vector<vector<int>>& dp, vector<int>& weight, vector<int>& value, int w, int n) {
    if(n==0 || w==0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(weight[n-1] <= w) {
        int take = value[n-1] + knapsack(dp, weight, value, w-weight[n-1], n-1);
        int not_take = knapsack(dp, weight, value, w, n-1);
        return dp[n][w] = max(take, not_take);
    }
    return dp[n][w] = knapsack(dp, weight, value, w, n-1);
}
