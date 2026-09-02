class Solution {
public:
    int solve(int ind, vector<int>&nums, vector<int>&dp){

        if(ind == 0){
            return nums[ind];
        }

        if(ind < 0){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int pick = nums[ind] + solve(ind-2, nums,dp);
        int notPick = 0 + solve(ind-1, nums,dp);
        return dp[ind] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n,-1);
        int prev = nums[0];
        int prev2 = 0;

        // dp[0] = nums[0];

        for(int i = 1; i<n; i++){
            int curr = 0;
            int pick = nums[i];
            if(i > 1)
                pick += prev2;
            int notPick = 0 + prev;
            curr = max(pick, notPick);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};