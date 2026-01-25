class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // Base case: if k is 1, the difference is always 0.
        if (k == 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int min_diff = INT_MAX;

        // The window will be from index i to i + k - 1
        for (int i = 0; i <= nums.size() - k; ++i) {
            int current_diff = nums[i + k - 1] - nums[i];
            min_diff = min(min_diff, current_diff);
        }

        return min_diff;
    }
};