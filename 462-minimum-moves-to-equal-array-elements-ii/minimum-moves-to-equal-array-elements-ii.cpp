class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int median = nums[n/2];
        int opnCnt = 0;

        for(auto &ele : nums){
            opnCnt += abs(median - ele);
        }

        return opnCnt;
        
    }
};