class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int el1 = INT_MIN;

        int cnt2 = 0;
        int el2 = INT_MIN;
        for(int i = 0; i<n; i++){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i]){
                cnt1++;
            }
            else if(el2 == nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        // Manual Check
        cnt1 = 0;
        cnt2 = 0;
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(el1 == nums[i]){
                cnt1++;
            }
            if(el2 == nums[i]){
                cnt2++;
            }
        }
        int mm = (int)(n/3)+1;
        if(cnt1 >= mm){
            ans.push_back(el1);
        }
        if(cnt2 >= mm){
            ans.push_back(el2);
        }

        return ans;
        // unordered_map<int,int>mpp;
        // vector<int>ans;
        // int mm = (n/3)+1;
        // for(int i = 0; i<n; i++)
        // {
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]] == mm){
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans;


        // unordered_map<int,int>mpp;
        // for(int i = 0; i<n;i++){
        //     mpp[nums[i]]++;
        // }

        // vector<int>ans;
        // for(auto&it: mpp){
        //     if(it.second > n/3){
        //         ans.push_back(it.first);
        //     }
        // }

        // return ans;



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