class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> v1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v1.push_back(grid[i][j]);
            }
        }

        int N = v1.size();

        vector<long long> pref_prd(N);
        pref_prd[0] = 1;
        for(int i=1;i<N;i++){
            pref_prd[i] = (pref_prd[i-1] * v1[i-1])%12345;
        }

        vector<long long> suff_prd(N);
        suff_prd[N-1] = 1;
        for(int i=N-2;i>=0;i--){
            suff_prd[i] = (suff_prd[i+1] * v1[i+1])%12345;
        }

        vector<long long> v2(N);
        for(int i=0;i<N;i++){
            v2[i] = (pref_prd[i] * suff_prd[i])%12345;
        }

        vector<vector<int>> final_ans(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                final_ans[i][j] = (int)v2[i * m + j];
            }
        }

        return final_ans;   
    }
};