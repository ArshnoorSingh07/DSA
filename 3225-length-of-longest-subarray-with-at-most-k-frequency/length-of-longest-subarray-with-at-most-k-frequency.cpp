class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int l=0;
        int r=0;
        int maxLen = 0;
        while(r < nums.size())
        {
            mpp[nums[r]]++;
            while(mpp[nums[r]] > k){
                mpp[nums[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};