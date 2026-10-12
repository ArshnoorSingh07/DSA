class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bit(32, 0);

        for(int num : nums){
            for(int i = 0; i < 32; i++){
                if(num & (1 << i)){
                    bit[i]++;
                }
            }
        }

        long long ans = 0;

        for(int j = 0; j < k; j++){
            long long num = 0;

            for(int i = 0; i < 32; i++){
                if(bit[i] > 0){
                    num |= (1LL << i);
                    bit[i]--;
                }
            }

            ans = (ans + (num * num) % MOD) % MOD;
        }

        return ans;
    }
};