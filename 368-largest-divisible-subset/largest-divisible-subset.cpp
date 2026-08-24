class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>hash(n);
        int last = 0;
        int maxi = 1;
        for(int i = 0; i<n; i++){
            hash[i] = i;
            for(int j = 0; j <i ; j++){
                if((nums[i] % nums[j] == 0) && dp[j] +1 > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                last = i;
            }
        }

        vector<int>temp;
        temp.push_back(nums[last]);
        while(hash[last] != last){
            last = hash[last];
            temp.push_back(nums[last]);
        }

        return temp;
    }

};