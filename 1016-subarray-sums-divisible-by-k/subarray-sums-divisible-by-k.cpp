class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pSum(n, 0);
        pSum[0] = ((nums[0] % k) + k) % k;

        for (int i = 1; i < n; i++) {
            pSum[i] = ((nums[i] + pSum[i - 1]) % k + k) % k;
        }

        int cnt = 0;
        unordered_map<int, int> mp;

        for (auto &ele : pSum) {
            if (ele == 0) {
                cnt++;
            }
            cnt += mp[ele];
            mp[ele]++;
        }

        return cnt;
    }
};
