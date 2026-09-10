class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        if(root == NULL) {
            return {0, 0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        int avg = sum / count;

        if(root->val == avg) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};