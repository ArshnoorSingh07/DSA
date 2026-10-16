class Solution {
public:
    const long long MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sqSum = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        tree[node].sqSum = (
            tree[node].sqSum +
            2 * val % MOD * tree[node].sum % MOD +
            val * val % MOD * len % MOD
        ) % MOD;

        tree[node].sum = (
            tree[node].sum +
            val * len
        ) % MOD;

        tree[node].lazy += val;
    }

    void push(int node, int l, int r) {
        if(tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, tree[node].lazy);
        apply(node * 2 + 1, mid + 1, r, tree[node].lazy);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if(ql > r || qr < l)
            return;

        if(ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum +
             tree[node * 2 + 1].sum) % MOD;

        tree[node].sqSum =
            (tree[node * 2].sqSum +
             tree[node * 2 + 1].sqSum) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.resize(4 * n);

        unordered_map<int, int> last;

        long long ans = 0;

        for(int r = 0; r < n; r++) {

            int previous = -1;

            if(last.count(nums[r]))
                previous = last[nums[r]];

            update(
                1,
                0,
                n - 1,
                previous + 1,
                r
            );

            ans = (ans + tree[1].sqSum) % MOD;

            last[nums[r]] = r;
        }

        return ans;
    }
};