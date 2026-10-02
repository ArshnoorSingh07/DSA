class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        unordered_set<int>st(nums.begin(), nums.end());
        for(auto x: st){
            if(st.find(x-1) == st.end()){
                int cnt = 1;
                int curr = x;
                while(st.find(curr+1) != st.end()){
                    cnt++;
                    curr++;
                }
                longest = max(cnt, longest);
            }
            
        }
        return longest;


        

        // if(n == 0){
        //     return 0;
        // }
        // sort(nums.begin(), nums.end());
        // int maxCnt = 1;
        // int cnt = 1;
        // for(int i = 1; i<n; i++)
        // {
        //     if(nums[i] == nums[i-1]){
        //         continue;
        //     }
        //     if(nums[i-1] + 1 == nums[i]){
        //         cnt++;
        //     }
        //     else cnt = 1;
        //     maxCnt = max(maxCnt, cnt);
        // }
        // return maxCnt;
    }
};