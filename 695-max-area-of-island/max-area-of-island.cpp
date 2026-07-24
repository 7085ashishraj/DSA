class Solution {
public:
    int  bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int area = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                //check for validation
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    area++;
                    q.push({nrow, ncol});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int maxArea = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int area = bfs(i,j,vis,grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};