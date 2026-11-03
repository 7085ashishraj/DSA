class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(),nums.end());
        int reqSum = (maxEle * n);
        int currSum = accumulate(nums.begin(), nums.end(), 0);

        return (maxEle * n) - currSum;    
    }
};