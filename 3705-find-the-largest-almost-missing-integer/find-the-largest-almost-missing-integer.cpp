class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto ele : nums) mp[ele]++;
        //for k = 1
        if(k==1){
            int ans = -1;
            for(auto const &pair : mp){
                if(pair.second == 1){
                    ans = max(ans, pair.first);
                }
            }
            return ans;
        }
        //for k=n
        if(k==n){
            return *max_element(nums.begin(), nums.end());
        }
        //for 1<k<n
        int ans = -1;
        if (mp[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (mp[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }
        return ans;
    }
};