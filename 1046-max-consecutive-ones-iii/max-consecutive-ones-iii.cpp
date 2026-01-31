class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int zeroCnt = 0;
        int maxLen = 0;
        while(right < n){
            if(nums[right] == 0) zeroCnt++;
            while(zeroCnt > k){
                if(nums[left] == 0){
                    zeroCnt--;
                
                } 
                left++;
            }
            maxLen = max(maxLen,right - left +1);
            right++; 
        
        }
        
        return maxLen;
    }
};