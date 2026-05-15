class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[high]>=nums[low]){
                return nums[low];
            }
            else if(nums[low]>nums[mid]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
        
    }
};