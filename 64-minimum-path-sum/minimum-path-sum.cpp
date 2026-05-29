class Solution {
public:

    int minPath(int i, int j, vector<vector<int>> &grid, vector<vector<int>>&dp){
        //base case
        if(i == 0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        //memoization

        if(dp[i][j] != -1) return dp[i][j];

        int up = minPath(i-1, j, grid, dp);
        int left = minPath(i,j-1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));
        return minPath(m-1, n-1, grid, dp);
    }
};