class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int score = nums[0];

        int mini = INT_MAX;
        int sec_mini = INT_MAX;

        //LOGIC-> nums[0] + mini + sec_mini;

        for(int i = 1;i < n; i++){
            if(nums[i] < mini){
                sec_mini = mini;
                mini = nums[i];
            }else if(nums[i] < sec_mini){
                sec_mini = nums[i];
            }
        }
        return score + mini + sec_mini;

    }
};