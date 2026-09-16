class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // Optimal approach
        int el = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        cnt = 0;
        for(int i = 0; i<n;i++){
            if(nums[i] == el){
                cnt++;
            }
        }

        if(cnt > n/2){
            return el;
        }

        return -1;


        // Using hashing
        // unordered_map<int,int>mpp;
        // for(int i = 0; i<n; i++){
        //     mpp[nums[i]]++;
        // }

        // for(auto &it: mpp){
        //     if(it.second > n/2){
        //         return it.first;
        //     }
        // }
        // return -1;

        // BRUTE FORCE:
        // for(int i = 0; i<n; i++)
        // {
        //     int cnt = 0;
        //     for(int j = 0; j<n; j++){
        //         if(nums[i] == nums[j]){
        //             cnt++;
        //         }
        //     }
        //     if(cnt > n/2){
        //         return nums[i];
        //     }
        // }
        // return -1;
    }
};