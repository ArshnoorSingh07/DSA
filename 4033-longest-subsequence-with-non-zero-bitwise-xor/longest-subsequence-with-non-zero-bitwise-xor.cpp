class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool nonZero = false;

        for (int x : nums) {
            xr ^= x;
            if (x != 0) nonZero = true;
        }

        int n = nums.size();

        if (xr != 0)
            return n;

        if (!nonZero)
            return 0;

        return n - 1;
    }
};