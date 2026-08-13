class Solution {
public:
    int solve(int ind, int s, vector<int>&arr,vector<vector<int>>&dp)
    {
        if(ind == 0){
            if(s == 0 && arr[0] == 0){
                return 2;
            }
            if(s==0 || arr[0] == s){
                return 1;
            }
            return 0;
        }
        
        if(dp[ind][s] != -1) return dp[ind][s];

        int notTake = solve(ind-1,s,arr,dp);
        int take = 0;
        if(arr[ind] <= s){
            take = solve(ind - 1, s- arr[ind], arr, dp);
        }
        return dp[ind][s] = take + notTake;
    }

    int findWays(vector<int>&arr, int target){
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1,-1));
        return solve(n-1, target, arr, dp);
    }

    int countPartitions(int n, int d, vector<int>&arr){
        int totSum = 0;
        for(auto &it:arr){
            totSum += it;
        }
        if(totSum - d  < 0 || (totSum-d) % 2 != 0) return 0;
        return findWays(arr, (totSum - d)/2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};