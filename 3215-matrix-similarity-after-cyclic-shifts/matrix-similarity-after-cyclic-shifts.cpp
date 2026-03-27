class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k%=n;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //k %= n;
                if((mat[i][(j+k)%n]) != mat[i][j]) return false;
            }
        }
        return true;
    }
};