class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int ele : nums){
            mp[ele]++;
        }
        for(auto ele : mp){
            if(ele.second > 1){
                return ele.first;
            }
        }
        return -1;
    }
};