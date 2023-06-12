//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  vector<vector<long long int>> dp;
    long long int solve(int ind, int coins[], int sum){
        if(sum==0) return 1;
        if(ind<0) return 0;
        if(dp[ind][sum]!=-1) return dp[ind][sum]; 
        long long int take=0,not_take=0;
        not_take = solve(ind-1,coins,sum);
        if(coins[ind] <=sum) take = solve(ind,coins,sum-coins[ind]);
        
        return dp[ind][sum] = take+not_take;
        
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        dp.resize(N, vector<long long int>(sum+1,-1));
        return solve(N-1, coins,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends