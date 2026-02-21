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

//make a pair class to define position(key) and value(vector of vector)
class Pair{
public:
    int col;//for(left -1 and right +1)
    int row; //depth(at root = 0)
    int val;
    Pair(int col, int row, int val){
        this->col = col;
        this->row = row;
        this->val = val;
    }
};


class Solution {
    void helper(TreeNode* node, int row,int col,vector<Pair>&acc){
        if(node == NULL) return;
        acc.emplace_back(col, row,node->val);
        helper(node->left, row+1, col-1, acc);
        helper(node->right, row+1, col + 1, acc);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        vector<Pair>nodes;
        //Collect all nodes with their ordinates
        helper(root,0,0,nodes);

        //Sort row->col->val
        sort(nodes.begin(), nodes.end(),[](const Pair& a, const Pair&b){
            if(a.col != b.col) return a.col < b.col;
            if(a.row != b.row) return a.row < b.row;
            return a.val < b.val;
        });

        //Group acc to column
        int prevCol = INT_MIN;
        for(const auto&p : nodes){
            if(p.col != prevCol){
                ans.push_back({});
                prevCol = p.col;
            }
            ans.back().push_back(p.val);
        }
        return ans;
    }
};