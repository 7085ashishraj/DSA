class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi_diff = -1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    int diff = nums[j] - nums[i];
                    maxi_diff = max(diff, maxi_diff);
                }
                
            }
        }
        return maxi_diff;
    }
};