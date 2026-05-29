class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n>0){
            sum+= n%10;
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = 1e9;
        for(int ele : nums){
            mini = min(mini, digitSum(ele));
        }
        return mini;

    }
};