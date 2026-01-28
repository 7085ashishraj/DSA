class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> res(n);
        int curr_idx = n-1;

        for(int i=1;i<n;i+=2){
            res[i] = nums[curr_idx];
            curr_idx--;

        }

        for(int i=0;i<n;i+=2){
            res[i] = nums[curr_idx];
            curr_idx--;

        }
        nums = res;
        
    }
};