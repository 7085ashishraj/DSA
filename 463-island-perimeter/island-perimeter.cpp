class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {

                    for (int k = 0; k < 4; k++) {
                        int nrow = i + delRow[k];
                        int ncol = j + delCol[k];

                        if (nrow < 0 || nrow >= n ||
                            ncol < 0 || ncol >= m ||
                            grid[nrow][ncol] == 0) {
                            perimeter++;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};