class Solution {
public:
    bool rowCheck(int row, vector<vector<int>> &mat){
        int cnt = 0;
        for(int i=0;i<mat[0].size();i++){
            if(mat[row][i]==1) cnt++;
        }
        return cnt==1;
    }

    bool colCheck(int col, vector<vector<int>> &mat){
        int cnt = 0;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col] == 1) cnt++;
        }
        return cnt==1;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) continue;
                else{
                    if(rowCheck(i,mat) && colCheck(j,mat)) cnt++;
                }
            }
        }
        return cnt;
    }
};