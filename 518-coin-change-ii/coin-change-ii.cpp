class Solution {
public:
    int solve(int ind, int t, vector<int>&coins, vector<vector<int>>&dp){
        
        if(ind == 0){
            if(t % coins[0] == 0){
                return 1;
            }
            else return 0;
        }

        if(dp[ind][t] != -1) return dp[ind][t];
        
        int notTake = solve(ind-1, t, coins, dp);
        int take = 0; 
        if(coins[ind] <= t){
            take = solve(ind, t - coins[ind], coins, dp); 
        }
        return dp[ind][t] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1,0), curr(amount+1,0);

        for(int tar = 0; tar <= amount; tar++) {
            if(tar % coins[0] == 0) {
                prev[tar] = 1;
            }
        }

        for(int ind = 1; ind < n; ind++)
        {
            for(int tar = 0; tar<= amount; tar++)
            {
                long long notTake = prev[tar];
                long long take = 0;
                if(coins[ind] <= tar){
                    take = curr[tar - coins[ind]];
                }
                curr[tar] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};