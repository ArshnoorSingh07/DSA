class Solution {
public:

    int solve(int ind, int prev, vector<int>&nums, vector<vector<int>>&dp){
        if(ind == nums.size()){
            return 0;
        }
        
        if(dp[ind][prev + 1] != -1){
            return dp[ind][prev + 1];
        }

        int len = 0 + solve(ind+1, prev, nums,dp);
        if(prev == -1 || nums[ind] > nums[prev]){
            len = max(len, 1 + solve(ind+1, ind, nums,dp));
        }
        return dp[ind][prev + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,1);
        int maxi = 1;
        for(int ind = 0; ind<n; ind++)
        {
            for(int prev = 0; prev< ind; prev++){
                if(nums[prev] < nums[ind]){
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }

        return maxi;

        // vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        // vector<int>next(n+1,0), curr(n+1,0);
        
        // for(int ind = n-1; ind>=0; ind--){
        //     for(int prev = ind-1; prev>=-1; prev--){
        //         int len = 0 + next[prev+1];
        //         if(prev == -1 || nums[ind] > nums[prev]){
        //             len = max(len, 1 + next[ind+1]);
        //         }
        //         curr[prev + 1] = len;
        //     }
        //     next = curr;
        // }

        // return next[-1 + 1];

    }
};