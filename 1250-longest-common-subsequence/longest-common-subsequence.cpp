class Solution {
public:

    int LCS(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        //base case
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + LCS(i-1, j-1, s1, s2,dp);
        }else{
            int l = LCS(i-1, j, s1, s2,dp);
            int r = LCS(i, j-1, s1, s2,dp);

            return dp[i][j] = max(l,r);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(),-1));
        return LCS(text1.length()-1, text2.length()-1, text1, text2,dp);
    }
};