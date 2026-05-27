class Solution {
public:
    int climb(int n, vector<int> &dp){
        if(n==1 || n==2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climb(n-1,dp) + climb(n-2, dp);
    }
    int climbStairs(int n) {
        
        //memoization
        vector<int> dp(n+1, -1);
        //dp[i] -> no of ways to reach i
        return climb(n, dp);
        
    }
};