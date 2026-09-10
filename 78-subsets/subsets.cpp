class Solution {
public:
    
    void solve(int idx, vector<int>& nums, vector<int>&temp, vector<vector<int>>&ans){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]); // take it
        solve(idx + 1, nums, temp, ans);
        
        temp.pop_back();
        // not take it
        solve(idx+1, nums, temp, ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0, nums, temp, ans);
        return ans;

        // int n = nums.size();
        // int subsets = 1 << n;
        // vector<vector<int>>ans;
        // for(int num = 0; num < subsets; num++){
        //     vector<int>temp;
        //     for(int i = 0; i<n; i++){
        //         if(num & (1 << i)){
        //             temp.push_back(nums[i]);
        //         }
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
    }
};