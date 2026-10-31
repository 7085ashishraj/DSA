class Solution {
public:
    int left = 0;
    int up = 1;
    int MOD = 1e9 + 7;
    int m;
    int n;

    //memoization
    int solve(vector<vector<int>>& grid, int i, int j, int moveDir,vector<vector<array<int, 2>>>& dp) {
        if (i >= m || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        if(dp[i][j][moveDir] != -1) return dp[i][j][moveDir];

        if (grid[i][j] == 1) {
            if (moveDir == left) return solve(grid, i + 1, j, up,dp);
            else return dp[i][j][moveDir] = solve(grid, i, j + 1, left,dp);
        }

        int totalPathCnt = 0;

        totalPathCnt = (totalPathCnt + solve(grid, i, j + 1, left,dp)) % MOD;
        totalPathCnt = (totalPathCnt + solve(grid, i + 1, j, up,dp)) % MOD;

        return dp[i][j][moveDir] = totalPathCnt;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<array<int, 2>>> dp(m+1, vector<array<int, 2>>(n, {-1, -1}));

        return solve(grid, 0, 0, left, dp);
    }
};