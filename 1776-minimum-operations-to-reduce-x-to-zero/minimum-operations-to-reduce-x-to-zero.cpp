class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int l = 0,  r = 0;
        int curr = 0;
        int target = total_sum - x;
        int maxi_len = -1;

        if(target < 0) return -1;
        if (target == 0) return n;
        while(r<n){
            curr += nums[r];
            while(curr > total_sum-x){
                curr -= nums[l];
                l++;
            }
            if (curr == target) {
                maxi_len = max(maxi_len, r - l + 1);
            }
            r++;
        }
        if(maxi_len == -1){
            return -1;
        }
        else return n - maxi_len;
        
    }
};