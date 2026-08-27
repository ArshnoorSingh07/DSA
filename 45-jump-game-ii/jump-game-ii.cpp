class Solution {
public:
    int solve(int ind, vector<int>&nums, vector<int>&dp)
    {
        int n = nums.size();
        if(ind >= n-1)
        {
            return 0;
        }
        if(dp[ind]!= -1){
            return dp[ind];
        }
        int mini = INT_MAX;
        for(int i = 1; i <= nums[ind]; i++){
            int next = solve(ind+i, nums,dp);
            if(next!=INT_MAX){
                mini = min(mini, 1 + next);
            }
        }
        return dp[ind]= mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r =0 ;
        while(r < n-1)
        {
            int farthest = 0;
            for(int ind = l; ind <= r; ind++){
                farthest = max(farthest, ind + nums[ind]);
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};