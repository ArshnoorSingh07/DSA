class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // // OPTIMAL -> IF ONLY TELL YES OR NO
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // int l = 0;
        // int r = n-1;
        // while(l < r){
        //     if(nums[l] + nums[r] == target){
        //         return {l,r};
        //     }
        //     else if(nums[l] + nums[r] < target){
        //         l++;
        //     }
        //     else r++;
        // }
        // return {};

        // BETTER
        unordered_map<int,int>mpp;
        for(int i = 0; i<nums.size(); i++){
            int needed = target - nums[i];
            if(mpp.find(needed) != mpp.end()){
                return {mpp[needed],i};
            }
            mpp[nums[i]] = i;
        }
        return {};

        // BRUTE FORCE:-> 
        // for(int i = 0; i<nums.size(); i++){
        //     for(int j = i+1; j<nums.size(); j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }
    }
};