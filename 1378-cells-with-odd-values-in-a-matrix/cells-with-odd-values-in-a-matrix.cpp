class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(auto& index : indices){
            int r = index[0];
            int c = index[1];

            for(int i=0; i<n; i++){
                res[r][i]++;
            }

            for(int j=0;j<m;j++){
                res[j][c]++;
            }

        }

        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(res[i][j] % 2 != 0) cnt++;
            }
        }
        return cnt;
        
    }
};