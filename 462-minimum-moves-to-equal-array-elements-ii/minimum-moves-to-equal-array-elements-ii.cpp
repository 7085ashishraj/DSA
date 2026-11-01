class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n/2];
        // if(n % 2 == 0) medianIdx = (n-1)/2;
        // else medianIdx = n/2;

        int opn = 0;
        for(auto &ele : nums){
            opn += abs(median - ele);
        }
        return opn;
        
    }
};