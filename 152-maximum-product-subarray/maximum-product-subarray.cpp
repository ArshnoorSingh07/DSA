class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // OPTIMAL APPROACH:->
        int n = nums.size();
        int minProd = nums[0];
        int maxProd = nums[0];
        int ans = nums[0];
        
        for(int i = 1; i<n; i++)
        {
            if(nums[i] < 0){
                swap(minProd, maxProd);
            }

            maxProd = max(nums[i], maxProd*nums[i]);
            minProd = min(nums[i], minProd*nums[i]);

            ans = max(ans, maxProd);
        }

        return ans;

        // BRUTE FORCE:->
        // int n = nums.size();
        // if(n==1){
        //     return nums[0];
        // }
        // int maxProd = INT_MIN;
        // for(int i = 0; i<n; i++)
        // {
        //     int prod = 1;
        //     for(int j = i; j<n; j++){
        //         prod *= nums[j];
        //         maxProd = max(maxProd, prod);
        //     }
        // }
        // return maxProd;
    }
};