class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        int l_sum = 0;
        for(int i=0;i<nums.size();i++){
            int r_sum = total_sum - l_sum - nums[i];
            if(l_sum == r_sum) return i;
            l_sum += nums[i];
        }
       
        return -1;
    }
};