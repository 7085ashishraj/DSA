class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(2);
        for(int i=0;i<n;i++){
            int idx = abs(nums[i])-1;
            if(nums[idx] < 0){
                result[0] = abs(nums[i]); // duplicate
            } else {
                nums[idx] *= -1;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) result[1] = i+1;
        }
        return result;
    }
};