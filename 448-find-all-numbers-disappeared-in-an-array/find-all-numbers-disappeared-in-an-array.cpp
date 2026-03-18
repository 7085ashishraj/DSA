class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //without using any extra space
        int n = nums.size();
        //Ist pass
        for(int i=0;i<n;i++){
            int idx_to_mark = abs(nums[i])-1;//to make 1-based to 0-based idx
            if(nums[idx_to_mark] > 0) nums[idx_to_mark] *= -1; //make it negative
        }
        //IInd pass
        vector<int> result;//returning list can't be considered as extra space
        for(int i=0;i<n;i++){
            if(nums[i]>0) result.push_back(i+1);
        }
        return result;
    }
};