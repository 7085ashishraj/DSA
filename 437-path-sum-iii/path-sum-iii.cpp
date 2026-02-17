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
    int helper(TreeNode* root, long long targetSum){
        if(root == NULL) return 0;
        int cnt = 0;
        if(targetSum == root->val){
            cnt++;
        }
        cnt += helper(root->left,targetSum - root->val);
        cnt += helper(root->right, targetSum - root->val);
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        // Count paths starting at this node
        int cnt = helper(root, targetSum);
        // Plus paths starting in left and right subtrees
        cnt += pathSum(root->left, targetSum);
        cnt += pathSum(root->right, targetSum);
        return cnt;

    }
};