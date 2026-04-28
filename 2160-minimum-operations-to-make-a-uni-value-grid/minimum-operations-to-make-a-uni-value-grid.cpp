class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]);
            }
        }
        int r = nums[0]%x;
        for(int i=1;i<nums.size();i++){
            if(r != nums[i] % x){
                return -1;
            }
        }
        sort(begin(nums), end(nums));
        int mid = nums[nums.size()/2];

        int ans = 0;

        for(auto &num: nums){
            ans += abs(num - mid)/x;
        }

        return ans;



    }
};