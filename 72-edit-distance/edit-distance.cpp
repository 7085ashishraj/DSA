class Solution {
public:
    int minDis(int i, int j, string &s1, string &s2,vector<vector<int>> &dp){
        //base case
        if(j == s2.length()) return (s1.length()-i);//for insertion
        if(i == s1.length()) return (s2.length()-j);//for deletion

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = minDis(i+1, j+1, s1,s2,dp);
        }
        int insert = 1 +  minDis(i, j+1, s1,s2,dp);
        int del = 1 + minDis(i+1,j, s1, s2, dp);
        int replace = 1 + minDis(i+1,j+1, s1, s2, dp);

        return dp[i][j] = min(insert, min(del, replace));

    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minDis(0, 0, word1, word2,dp);
    }
};