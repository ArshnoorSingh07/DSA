class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        
        vector<int> diff(n);
        
        long long totalDiff = 0;
        int maxi = 0;
        
        for(int i = 0; i < n; i++){
            diff[i] = abs(nums1[i] - nums2[i]);
            totalDiff += diff[i];
            maxi = max(maxi, diff[i]);
        }
        
        long long k = (long long)k1 + k2;
        
        if(k >= totalDiff)
            return 0;
        
        int low = 0;
        int high = maxi;
        
        while(low < high){
            int mid = low + (high - low) / 2;
            
            long long operations = 0;
            
            for(int d : diff){
                if(d > mid)
                    operations += d - mid;
            }
            
            if(operations <= k)
                high = mid;
            else
                low = mid + 1;
        }
        
        int limit = low;
        
        long long used = 0;
        
        for(int& d : diff){
            if(d > limit){
                used += d - limit;
                d = limit;
            }
        }
        
        long long remaining = k - used;
        
        sort(diff.rbegin(), diff.rend());
        
        for(int i = 0; i < n && remaining > 0; i++){
            if(diff[i] > 0){
                diff[i]--;
                remaining--;
            }
        }
        
        long long ans = 0;
        
        for(long long d : diff){
            ans += d * d;
        }
        
        return ans;
    }
};