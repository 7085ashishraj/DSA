class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftSum(n);
        vector<int>rightSum(n);
        vector<int> res(n,0);
        leftSum[0] = 0;
        rightSum[n-1] = 0;
        //leftSum
        for(int i=1;i<n;i++){
            leftSum[i] = leftSum[i-1] + nums[i-1];
        }
        //rightSum
        for(int i=n-2;i>=0;i--){
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }
        //result
        for(int i=0;i<n;i++){
            res[i] = abs(leftSum[i] - rightSum[i]);
        }
        return res;
    }
};