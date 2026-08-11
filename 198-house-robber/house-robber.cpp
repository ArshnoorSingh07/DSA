class Solution {
public:
    int dp[100];

    int solve(int n, vector<int>&nums)
    {
        if(n==0) return nums[0];
        dp[0] = nums[0];
        for(int i = 1; i< nums.size(); i++)
        {
            int pick = nums[i];
            if(i > 1){
                pick+=dp[i-2];
            }
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        memset(dp,-1, sizeof(dp));
        int n = nums.size();
        return solve(n-1, nums);
    }
};