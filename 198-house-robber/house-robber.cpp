class Solution {
public:
    int dp[100];

    int solve(int n, vector<int>&nums)
    {
        if(n == 0) return nums[0];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int left = nums[n] + solve(n-2, nums);
        int right = 0 + solve(n-1, nums);
        return dp[n] = max(left, right);
    }

    int rob(vector<int>& nums) {
        memset(dp,-1, sizeof(dp));
        int n = nums.size();
        return solve(n-1, nums);
    }
};