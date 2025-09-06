class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_pdt(n);
        vector<int> suff_pdt(n);
        vector<int> ans(n);

        pre_pdt[0] = 1;
        suff_pdt[n-1] = 1;

        for(int i=1;i<n;i++){
           pre_pdt[i] = pre_pdt[i-1] * nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
           suff_pdt[i] = suff_pdt[i+1] * nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i] = pre_pdt[i]*suff_pdt[i];
        }
        return ans;
    }
};