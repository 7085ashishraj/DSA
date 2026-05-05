class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }

        double maxSum = sum;

        int i = 0;
        int j = k;
        while(j < n){
            sum += nums[j];
            sum -= nums[i];
            maxSum = max(sum, maxSum);
            i++;
            j++;
        }
        return maxSum/k;
        
    }
};