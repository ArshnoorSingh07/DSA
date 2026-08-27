class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0;
        for(int i= 0; i<n;i++)
        {
            if(i > maxIdx){
                return false;
            }
            if(nums[i] + i > maxIdx){
                maxIdx = nums[i] + i;
            }
        }
        return true;
    }
};