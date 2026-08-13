class Solution {
public:
    int solve(int ind,int T, vector<int>&coins, vector<vector<int>>&dp)
    {
        if(ind == 0){
            if(T%coins[ind] == 0) return T/coins[ind];
            else return 1e9;
        }
        if(dp[ind][T] != -1) return dp[ind][T];

        int notTake = 0 + solve(ind-1,T, coins,dp);
        
        int take = INT_MAX;
        
        if(coins[ind] <= T){
            take = 1 + solve(ind, T-coins[ind], coins,dp);
        }
        return dp[ind][T] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1, amount, coins,dp);
        if(ans >= 1e9){
            return -1;
        } else return ans;
    }
};