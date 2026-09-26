class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int sum = 0;
        // int total = n * (n + 1) /2;
        // for(auto it: nums){
        //     sum+=it;
        // }
        // return total - sum;

        int n = nums.size();
        int ans = n;
        for(int i = 0; i<nums.size(); i++)
        {
            ans ^= i ^ nums[i];
        }
        return ans;
    }
};