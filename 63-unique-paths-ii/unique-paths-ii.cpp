class Solution {
public:
    int uniquePaths(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        //base case
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j==0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int left = uniquePaths(i, j-1, obstacleGrid, dp);
        int up = uniquePaths(i-1, j, obstacleGrid, dp);

        return dp[i][j] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //memoization
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return uniquePaths(m-1, n-1, obstacleGrid, dp);
        
    }
};