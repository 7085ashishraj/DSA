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
    void helper(TreeNode* root, vector<int>&sumArr,vector<vector<int>>&ans, int sum, int targetSum){
        if(root == NULL) return;
        sumArr.push_back(root->val);
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(sumArr);
            }
        }else{
            helper(root->left, sumArr, ans, sum, targetSum);
            helper(root->right, sumArr, ans, sum, targetSum);
        }
        sumArr.pop_back();//backtrack require
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> sumArr;
        helper(root, sumArr, ans, 0, targetSum);
        return ans;
    }
};