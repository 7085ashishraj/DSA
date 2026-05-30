class Solution {
public:
    int lps(int i, int j, string &s,vector<vector<int>> &dp ){
        //base case
        if(i == j) return 1;
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j] = 2+lps(i+1, j-1, s, dp);
        }
        else{
            int l = lps(i, j-1,s,dp);
            int r = lps(i+1, j,s,dp);
            return dp[i][j] = max(l,r);
        }
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return  n - lps(0,n-1,s, dp);

    }
};