class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0, minLen = INT_MAX;
        while(r < n){
            sum += nums[r];

            while(sum >= target){
                sum -= nums[l];
                minLen = min(minLen, r-l+1);
                l++;
                
                
            }
            r++;
        }
        if(minLen > n) return 0;
        else return minLen;
    }
};