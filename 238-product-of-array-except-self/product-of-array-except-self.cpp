class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int pdt = 1;
        int pdt2 = 1;

        int noz = 0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) noz++;
            pdt *= nums[i];
            if(nums[i]!=0) pdt2 *= nums[i];
        }

        if(noz > 1) pdt2 = 0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) nums[i] = pdt2;
            else nums[i] = pdt / nums[i];
        }

        return nums;

    }
};