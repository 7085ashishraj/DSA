class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<n/2;i++){ //[4,1,5,1,2,5,1,5,5,4] -> not always first and last will be maximum
            ans = max(ans, nums[i]+nums[n-1-i]);
        }
        return ans;
        
    }
};