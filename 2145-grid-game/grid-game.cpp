class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        vector<long long> topPSum(n);
        vector<long long> bottomPSum(n);

        topPSum[0] = grid[0][0];
        bottomPSum[0] = grid[1][0];

        for(int i=1; i<n; i++){
            topPSum[i] = topPSum[i-1] + grid[0][i];
            bottomPSum[i] = bottomPSum[i-1] + grid[1][i];
        }

        long long ans = LLONG_MAX;
        for(int j=0; j<n; j++){
            long long top_rem = topPSum[n-1] - topPSum[j];
            long long bottom_rem = (j>0) ? bottomPSum[j-1] : 0;

            long long robot2 = max(top_rem, bottom_rem);
            ans = min(ans, robot2);
        }
        return ans;
    }
};