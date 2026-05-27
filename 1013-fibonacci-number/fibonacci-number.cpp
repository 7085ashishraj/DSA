class Solution {
public:
    int calcFib(int n, vector<int> &dp){
        if(n==0 || n==1) return n;
        //memoization
        if(dp[n] != -1) return dp[n];
        return dp[n] = calcFib(n-1, dp) + calcFib(n-2, dp);
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return calcFib(n, dp);
    }
};