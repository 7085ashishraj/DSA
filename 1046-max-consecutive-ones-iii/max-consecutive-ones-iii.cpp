class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, zeroCnt = 0, maxLen = 0;

        while (r < n) {
            if (nums[r] == 0) zeroCnt++;

            while (zeroCnt > k) {
                if (nums[l] == 0) zeroCnt--;
                l++;
            }
            int len = r - l + 1;
            maxLen = max(maxLen, len);

            r++;
        }

        return maxLen;
    }
};