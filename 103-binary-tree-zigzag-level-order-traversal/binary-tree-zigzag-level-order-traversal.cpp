/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);

        bool leftToRight = 1;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>level(size);
            for(int i = 0; i<size; i++)
            {
                int index;
                if(!leftToRight){
                    index = size - i - 1;
                }else{
                    index = i;
                }

                auto it = q.front();
                q.pop();
                level[index] = it->val;

                if(it->left != nullptr){
                    q.push(it->left);
                }

                if(it->right){
                    q.push(it->right);
                }
            }

            leftToRight = !leftToRight;
            ans.push_back(level);            

        }
        return ans;
    }
};

