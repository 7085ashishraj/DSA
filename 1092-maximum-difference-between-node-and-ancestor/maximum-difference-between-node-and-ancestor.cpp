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
    int ans = 0;

    void solve(TreeNode* node, int mini, int maxi){
        if(node == NULL) return;

        mini = min(mini, node->val);
        maxi = max(maxi, node->val);

        ans = max(ans, maxi - mini);

        solve(node->left, mini, maxi);
        solve(node->right, mini, maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,root->val, root->val);
        return ans;

    }
};