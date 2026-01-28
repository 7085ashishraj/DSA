class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi_sum = 0;
        for(int i=0;i<n/2;i++){ //[4,1,5,1,2,5,1,5,5,4] -> not always first and last will be maximum
            maxi_sum = max(maxi_sum, nums[i]+nums[n-i-1]);
        }
        return maxi_sum;
        
    }
};