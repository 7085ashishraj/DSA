class Solution {
public:
    int countSubTrees(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + countSubTrees(root->left) + countSubTrees(root->right);

    }

    int getSum(TreeNode* root){
        if(root == NULL) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        //int cnt = 0;
        if(root == NULL) return 0;
        int cnt = averageOfSubtree(root->left) + averageOfSubtree(root->right);
        int sum = getSum(root);
        int nodes = countSubTrees(root);
        if(sum / nodes == root->val){
            cnt++;
        }
        return cnt;

    }
};