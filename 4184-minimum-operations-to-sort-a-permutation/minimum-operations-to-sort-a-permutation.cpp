class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int pos = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }

        int ans = INT_MAX;

        bool forward = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                forward = false;
                break;
            }
        }

        if (forward) {
            ans = min(ans, pos);
            ans = min(ans, n - pos + 2);
        }

        bool backward = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos - i + n) % n] != i) {
                backward = false;
                break;
            }
        }

        if (backward) {
            ans = min(ans, pos + 2);
            ans = min(ans, n - pos);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};