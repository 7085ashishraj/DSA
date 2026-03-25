class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long tot_sum = 0;

        for(auto &row : grid){
            for(int &x : row){
                tot_sum += x;
            }
        }

        long long ans = tot_sum / 2;
        if(tot_sum % 2 != 0) return false;

        long long grid_sum = 0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                grid_sum += grid[i][j];
            }
            if(grid_sum == ans) return true;
        }
        vector<long long> col(n,0);
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                col[j] += grid[i][j];
            }
        }

        grid_sum = 0;
        for(int i=0;i<n-1;i++){
            grid_sum += col[i];
            if(grid_sum == ans) return true;

        }
        return false;

        
    }
};