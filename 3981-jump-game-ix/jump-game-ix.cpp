class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 0);

        vector<int>preMax(n, 0);
        preMax[0] = nums[0];

        for(int i=1;i<n;i++){
            preMax[i] = max(preMax[i-1], nums[i]);
        }

        int suffMin = INT_MAX;
        for(int i=n-1; i>=0; i--){
            if(preMax[i] > suffMin){
                result[i] = (i+1 < n) ? result[i+1]:preMax[i];
            }else{
                result[i] = preMax[i];
            }
            suffMin = min(suffMin, nums[i]);
        }

        return result;

        
    }
};