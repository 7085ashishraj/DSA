class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int cur_val = 0;
        for(int num : nums){
            cur_val = (cur_val * 2 + num) % 5;
            ans.push_back(cur_val % 5 == 0);
        }
        return ans;
    }
};