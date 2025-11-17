class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_1_idx = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                if(last_1_idx != -1){
                    if(i-last_1_idx -1 < k){
                        return false;
                    }
                }
                last_1_idx = i;
            }    
        }
        return true;
    }
};