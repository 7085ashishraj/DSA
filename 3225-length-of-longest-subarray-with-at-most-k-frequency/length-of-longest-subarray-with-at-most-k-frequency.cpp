class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int l = 0;
        int r = 0;
        int maxiLen = 0;

        while (r < n) {
            mp[nums[r]]++; // curr ele ko window m add karnege
            // If frequency becomes greater than k,
            // shrink the window
            while (mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            maxiLen = max(maxiLen, r - l + 1);
            r++;
        }
        return maxiLen;
    }
};