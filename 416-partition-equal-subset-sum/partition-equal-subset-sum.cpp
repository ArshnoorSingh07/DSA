class Solution {
public:
    bool subsetSumToK(int n, int target, vector<int>&arr)
    {
        vector<bool>prev(target+1,0);
        vector<bool>curr(target+1,0);
        prev[0] = curr[0] = true;
        for(int ind = 1; ind<arr.size(); ind++)
        {
            for(int k = 1; k<= target;k++){
                bool notTake = prev[k];
                bool take = false;
                if(arr[ind] <= k){
                    take = prev[k- arr[ind]];
                }
                curr[k] = take || notTake;
            }
            prev = curr;
        }
        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            totSum+=nums[i];
        }
        if(totSum % 2) return false;
        int target = totSum/2;
        return subsetSumToK(nums.size() -1, target, nums);
    }
};