class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> pSum(nums.size());
        pSum[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            pSum[i] = pSum[i-1] + nums[i];
        }
        return pSum;
    }
};