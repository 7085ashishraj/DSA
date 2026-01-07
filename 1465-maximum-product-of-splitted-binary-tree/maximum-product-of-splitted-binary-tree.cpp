class Solution {
public:
    long long MOD = 1e9 + 7;
    long long res = 0;

    long long DFS(TreeNode* node) {
        if(!node) return 0;

        node -> val += DFS(node->left) + DFS(node->right);
        return node->val;
    }
    int maxProduct(TreeNode* root) {

        long long total_sum = DFS(root);

        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!node) continue;

            long long curr = (total_sum - node->val) * node->val;
            res = max(res, curr); 
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return res % MOD;
        
    }
};