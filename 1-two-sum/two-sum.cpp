class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }

        // unordered_map<int,int>mpp;
        // for(int i = 0; i<nums.size(); i++){
        //     int needed = target - nums[i];
        //     if(mpp.find(needed) != mpp.end()){
        //         return {mpp[needed],i};
        //     }
        //     mpp[nums[i]] = i;
        // }
        return {};
    }
};