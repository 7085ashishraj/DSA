class Solution {
public:
    int getSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int minIdx = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int dig_sum = getSum(nums[i]);
            if(dig_sum == i){
                minIdx = min(minIdx, i);
            }
        }
        return (minIdx == INT_MAX) ? -1 : minIdx;
    }
};