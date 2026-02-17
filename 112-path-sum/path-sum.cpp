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
    bool helper(TreeNode* root,int sum,int targetSum){
        if(root == NULL){
            return false;
        }
        sum+=root->val;
        if(root->left == NULL && root->right == NULL){
            if(targetSum == sum){
                return true;
            }else{
                return false;
            }
        }
        bool l = helper(root->left,sum,targetSum);
        bool r = helper(root->right,sum,targetSum);
        return l ||r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, 0,targetSum);
    }
};