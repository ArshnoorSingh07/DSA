class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }

        // vector<int>temp;
        // int cnt = 0;
        // for(auto&it: nums){
        //     if(it != 0){
        //         temp.push_back(it);
        //     }else{
        //         cnt++;
        //     }
        // }

        // for(int i = 1; i <= cnt; i++){
        //     temp.push_back(0);
        // }

        // nums.clear();
        // for(int it: temp){
        //     nums.push_back(it);
        // }

    }
};