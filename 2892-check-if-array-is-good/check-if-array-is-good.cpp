class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        //sort to check if base[n] -> [1,2,3,4....]
        sort(nums.begin(), nums.end());

        for(int i=0;i<n-1;i++){
            if(nums[i] != i+1){
                return false;
            }
        }

        if(nums[n-1] != n-1) return false;
        else return true;
        
    }
};