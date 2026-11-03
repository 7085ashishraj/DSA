class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        //transform it into 1-D
        vector<int> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res.push_back(grid[i][j]);
            }
        }

        //check remainder of other ele with first if not equal then not possible to make it uni-value

        int r = res[0]%x;
        for(int i=0;i<res.size();i++){
            if(r!=res[i]%x) return -1;
        }

        sort(res.begin(), res.end());

        int mid = res[res.size()/2];

        int opnCnt = 0;
        for(int i=0;i<res.size();i++){
            opnCnt += abs(res[i] - mid)/x;
        }
        return opnCnt;

    }
};