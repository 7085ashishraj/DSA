class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int find(vector<int> &nums, int start, int target){
        int j = lower_bound(nums.begin()+start, nums.end(), target) - nums.begin();

        if(j < n && nums[j] == target){
            return j;
        }

        return -1;
    }

    int solve(int i, int inc, vector<int> &nums){

        if(dp[i][inc] != -1) return dp[i][inc];

        int currVal = nums[i] + inc;
        int len = 1;

        //option 1:- find (currVal + 1)
        int j = find(nums, i+1, currVal+1);
        if(j != -1){
            len = max(len, 1 + solve(j, 0, nums));
        }

        //option 2:- find (currVal) directly and then increment by 1
        j = find(nums, i+1, currVal);
        if(j != -1){
            len = max(len, 1 + solve(j, 1, nums));
        }
        return dp[i][inc] = len;
        
    }
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        dp.assign(n+1, vector<int>(2, -1));

        int ans = 1;

        for(int i=0;i<n;i++){
            ans = max({ans, solve(i, 0, nums), solve(i, 1, nums)});
        }

        return ans;
        
    }
};