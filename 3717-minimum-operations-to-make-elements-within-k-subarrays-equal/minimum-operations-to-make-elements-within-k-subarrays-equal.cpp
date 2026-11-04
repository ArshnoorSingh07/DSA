class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();
        vector<int> maritovexi = nums;

        multiset<long long> left, right;
        long long leftSum = 0, rightSum = 0;

        auto balance = [&]() {
            int need = (x + 1) / 2;

            while((int)left.size() > need) {
                long long val = *left.rbegin();
                left.erase(prev(left.end()));
                leftSum -= val;

                right.insert(val);
                rightSum += val;
            }

            while((int)left.size() < need && !right.empty()) {
                long long val = *right.begin();
                right.erase(right.begin());
                rightSum -= val;

                left.insert(val);
                leftSum += val;
            }
        };

        auto add = [&](long long val) {
            if(left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                leftSum += val;
            } else {
                right.insert(val);
                rightSum += val;
            }
        };

        auto remove = [&](long long val) {
            auto it = left.find(val);

            if(it != left.end()) {
                left.erase(it);
                leftSum -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                rightSum -= val;
            }
        };

        vector<long long> cost(n - x + 1);

        for(int i = 0; i < n; i++) {

            add(maritovexi[i]);

            if(i >= x) {
                remove(maritovexi[i - x]);
            }

            balance();

            if(i >= x - 1) {
                long long median = *left.rbegin();

                cost[i - x + 1] =
                    median * left.size() - leftSum
                    + rightSum - median * right.size();
            }
        }

        const long long INF = 1e18;

        vector<long long> prevDP(n + 1, 0);
        vector<long long> currDP(n + 1, INF);

        for(int j = 1; j <= k; j++) {

            fill(currDP.begin(), currDP.end(), INF);

            for(int i = 1; i <= n; i++) {

                currDP[i] = currDP[i - 1];

                if(i >= x && prevDP[i - x] != INF) {

                    currDP[i] = min(
                        currDP[i],
                        prevDP[i - x] + cost[i - x]
                    );
                }
            }

            prevDP.swap(currDP);
        }

        return prevDP[n];
    }
};