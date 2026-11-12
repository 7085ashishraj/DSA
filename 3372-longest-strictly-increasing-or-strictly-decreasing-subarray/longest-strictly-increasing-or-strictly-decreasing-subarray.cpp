class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1;
        int maxi_len = 1;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                inc++;
                dec = 1;
            }
            else if(nums[i] < nums[i-1]){
                dec++;
                inc = 1;
            }
            else{
                inc = 1;
                dec = 1;
            }
            maxi_len = max(maxi_len, max(inc, dec));
        }
        return maxi_len;
    }
};