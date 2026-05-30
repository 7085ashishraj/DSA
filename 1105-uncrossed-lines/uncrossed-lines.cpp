class Solution {
public:
    int maxLines(int i, int j,vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp ){
        //base case
        if(i<0 || j<0) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        if(nums1[i] == nums2[j]){
            return dp[i][j] = 1 + maxLines(i-1, j-1, nums1, nums2, dp);
        }
        else{
            int l = maxLines(i, j-1, nums1,nums2, dp);
            int r = maxLines(i-1, j, nums1, nums2, dp);
            return dp[i][j] = max(l,r);
        }
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m,vector<int>(n, -1));

        return maxLines(m-1, n-1, nums1, nums2, dp);
    }
};