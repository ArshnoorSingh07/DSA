class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        // First calculate the total sum of all numbers
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If (target + totalSum) is odd or target > totalSum, no valid partition exists
        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum) return 0;

        // We now need to count subsets with sum = (target + totalSum) / 2
        int newTarget = (totalSum + target) / 2;

        // Create DP table: dp[i][j] = number of ways to make sum j using first i numbers
        vector<vector<int>> dp(n + 1, vector<int>(newTarget + 1, 0));

        // Base case: One way to form sum 0 (by taking no elements)
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        // Fill DP table iteratively
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= newTarget; j++) {
                // Exclude current element
                dp[i][j] = dp[i - 1][j];

                // Include current element if it does not exceed current target j
                if (nums[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][newTarget];
    }
};
