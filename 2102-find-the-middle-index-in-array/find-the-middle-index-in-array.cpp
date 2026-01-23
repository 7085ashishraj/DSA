class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pSum(n);
        vector<int>sSum(n);
        
        if(n==1) return 0;

        pSum[0] = nums[0];
        sSum[n-1] = nums[n-1];

        for(int i=1;i<nums.size();i++){
            pSum[i] = pSum[i-1] + nums[i];
        }

        for(int i=n-2;i>=0;i--){
            sSum[i] = sSum[i+1] + nums[i];
        }

        for(int i=0;i<nums.size();i++){
            if(pSum[i] == sSum[i]){
                return i;
            }
        }
        return -1;

    }
};