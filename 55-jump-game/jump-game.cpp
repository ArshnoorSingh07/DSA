class Solution {
public:
    bool solve(int ind, vector<int>&nums,vector<int>&dp)
    {
        int n = nums.size();
        if(ind >= n-1){
            return true;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }

        int farthest = min(n-1, ind + nums[ind]);

        for(int i = ind+1; i <= farthest; i++){
            if(solve(i,nums,dp)){
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(0, nums,dp);
    }
};