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
    //total no. of nodes
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;
        int l = countNodes(root->left);
        int r = countNodes(root->right);
        return l+r+1;
    }

    bool isComplete(int i, TreeNode* root, int totalNodes){
        //base case
        if(root == NULL) return true;
        if(i >= totalNodes) return false;
        bool l = isComplete(2*i+1, root->left, totalNodes);
        bool r = isComplete(2*i+2, root->right, totalNodes);

        return l && r;
    }
    
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        return isComplete(0, root, totalNodes);

    }
};