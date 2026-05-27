class Solution {
public:
    int robbed(int i, vector<int> &nums, vector<int> &dp){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int rob = nums[i] + robbed(i-2, nums,dp);
        int notrob = robbed(i-1, nums, dp);

        return dp[i] = max(rob, notrob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //memoization
        vector<int> dp(n, -1);
        
        return robbed(nums.size()-1, nums,dp);
    }
};