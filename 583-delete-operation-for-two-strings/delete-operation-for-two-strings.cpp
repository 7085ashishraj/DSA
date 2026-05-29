class Solution {
public:
    int minDis(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        //memoization
        if(i < 0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + minDis(i-1, j-1, s1, s2, dp);
        }
        else{
            int l = minDis(i-1, j, s1, s2, dp);
            int r = minDis(i,j-1,s1,s2, dp);

            return dp[i][j] = max(l,r);
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int lcs_len =  minDis(m-1, n-1,word1, word2, dp);

        return (m-lcs_len) +  (n-lcs_len);
    }
};