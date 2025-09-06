class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        //vector<int> ans;
        //int sum = nums[0];
        //ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
            //ans.push_back(sum);
            
        }
        return nums;
    }
};