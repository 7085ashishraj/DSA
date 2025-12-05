class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total_sum = 0;
        for(auto &num : nums){
            total_sum += num;
        }
        if(total_sum % 2 == 0){
            return nums.size() - 1;
        }
        return 0;
    }
};