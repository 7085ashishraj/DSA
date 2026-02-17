class Solution {
public:

TreeNode* buildTree(int ps, int pe,vector<int>& postorder,int is, int ie,vector<int>& inorder) {
    if (ps > pe || is > ie) return NULL;

        // root = LAST element in postorder
        TreeNode* root = new TreeNode(postorder[pe]);

        int inIndex = -1;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == root->val) {
                inIndex = i;
                break;
            }
        }

        int count = inIndex - is;  // left subtree size

        // LEFT subtree
        root->left = buildTree(ps,ps + count - 1,postorder,is,inIndex - 1,inorder);

        // RIGHT subtree
        root->right = buildTree(ps + count,pe - 1,postorder,inIndex + 1,ie,inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder) {

        int n = inorder.size();

        return buildTree(0, n - 1,postorder,0, n - 1,inorder);
    }
};
