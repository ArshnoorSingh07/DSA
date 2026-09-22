class Solution {
public:
    struct Node {
        int product = 1;
        array<int, 5> count{};
    };

    int k;
    int size;
    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node result;

        result.product =
            (1LL * left.product * right.product) % k;

        result.count = left.count;

        for (int remainder = 0; remainder < k; remainder++) {
            int newRemainder =
                (1LL * left.product * remainder) % k;

            result.count[newRemainder] += right.count[remainder];
        }

        return result;
    }

    Node identityNode() {
        Node result;
        result.product = 1 % k;
        return result;
    }

    Node createLeaf(int value) {
        Node result;
        int remainder = value % k;

        result.product = remainder;
        result.count[remainder] = 1;

        return result;
    }

    void update(int index, int value) {
        int position = size + index;

        tree[position] = createLeaf(value);
        position /= 2;

        while (position >= 1) {
            tree[position] =
                mergeNodes(tree[2 * position],
                           tree[2 * position + 1]);

            position /= 2;
        }
    }

    // Query on range [left, right)
    Node query(int left, int right) {
        left += size;
        right += size;

        Node leftResult = identityNode();
        Node rightResult = identityNode();

        while (left < right) {
            if (left % 2 == 1) {
                leftResult = mergeNodes(leftResult, tree[left]);
                left++;
            }

            if (right % 2 == 1) {
                right--;
                rightResult = mergeNodes(tree[right], rightResult);
            }

            left /= 2;
            right /= 2;
        }

        return mergeNodes(leftResult, rightResult);
    }

    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {
        k = K;
        int n = nums.size();

        size = 1;
        while (size < n) {
            size *= 2;
        }

        tree.assign(2 * size, identityNode());

        for (int i = 0; i < n; i++) {
            tree[size + i] = createLeaf(nums[i]);
        }

        for (int i = size - 1; i >= 1; i--) {
            tree[i] =
                mergeNodes(tree[2 * i], tree[2 * i + 1]);
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(index, value);

            Node result = query(start, n);
            answer.push_back(result.count[x]);
        }

        return answer;
    }
};