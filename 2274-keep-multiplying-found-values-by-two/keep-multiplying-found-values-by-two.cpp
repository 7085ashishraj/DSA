class Solution {
public:
    bool isAvailable(vector<int>& nums,int x){
        for(int i=0;i<nums.size();i++){
            if(nums[i] == x) return true;
        }
        return false;
    }
    int findFinalValue(vector<int>& nums, int original) {
        while(isAvailable(nums,original)){
            original *= 2;
        }
        return original;
    }
};