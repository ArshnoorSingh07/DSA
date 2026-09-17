class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i = 0; i<n;i++){
            mpp[nums[i]]++;
        }

        vector<int>ans;
        for(auto&it: mpp){
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }

        return ans;



        // Brute force
    //     vector<int>ans;
    //     for(int i =0; i<n;i++)
    //     {
    //         if(ans.size() == 0 || ans[0] != nums[i]){
    //             int cnt = 0;
    //             for(int j = 0; j<n;j++){
    //                 if(nums[i] == nums[j]){
    //                     cnt++;
    //                 }
    //             }
    //             if(cnt > n/3){
    //                 ans.push_back(nums[i]);
    //             }
    //         }
    //         if(ans.size() == 2){
    //             break;
    //         }
    //     }
    //     return ans;

    }
};