class Solution {
public:
    int solve(int ind, vector<int>&nums, vector<int>&dp)
    {
        int n = nums.size();
        if(ind >= n-1){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int minJumps = INT_MAX;
        int farthest = min(n-1, ind + nums[ind]);

        for(int i = ind+1; i <= farthest; i++){
            int nextJump = solve(i, nums,dp);

            if(nextJump != INT_MAX){
                minJumps = min(minJumps, 1 + nextJump);
            }
        }

        return dp[ind] = minJumps;

    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(0, nums,dp);
    }
};