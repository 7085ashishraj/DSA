class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int resultLevel = 0;

        //using BFS

        queue<TreeNode*> que;
        que.push(root);

        int currLevel = 1;

        //normal BFS traversal
        while(!que.empty()) {
            int n = que.size();

            int sum = 0;

            //travesing all element at current level
            while(n--){
                TreeNode* temp = que.front();
                que.pop();

                sum += temp->val;

                if(temp->left){  //will check if there is child of curr node
                    que.push(temp->left);
                }

                if(temp->right){
                    que.push(temp->right);
                }
            }

            if(sum > maxSum) {
                maxSum = sum;
                resultLevel = currLevel; //update resultLevel as well
            }
            currLevel++;

        }
        return resultLevel;

    }
};