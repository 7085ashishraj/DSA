class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pPdt(n);
        vector<int>sPdt(n);
        vector<int> ans(n);
        
        pPdt[0] = 1;
        sPdt[n-1] = 1;

        for(int i=1;i<nums.size();i++){
            pPdt[i] = pPdt[i-1] * nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
            sPdt[i] = sPdt[i+1] * nums[i+1];
        }

        for(int i=0;i<nums.size();i++){
            ans[i] = pPdt[i] * sPdt[i];
        }

        return ans;

    }
};