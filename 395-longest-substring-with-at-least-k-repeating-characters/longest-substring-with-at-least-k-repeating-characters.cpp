class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxi = 0;
        // Try every possible number of unique characters
        for (int target = 1; target <= 26; target++) {
            vector<int> freq(26, 0);

            int l = 0;
            int r = 0;

            int unique = 0;
            int countK = 0;
            while (r < s.size()) {
                // Add s[r]
                if (freq[s[r] - 'a'] == 0) {
                    unique++;
                }
                freq[s[r] - 'a']++;
                if (freq[s[r] - 'a'] == k) {
                    countK++;
                }
                // If unique characters exceed target
                while (unique > target) {
                    if (freq[s[l] - 'a'] == k) {
                        countK--;
                    }
                    freq[s[l] - 'a']--;
                    if (freq[s[l] - 'a'] == 0) {
                        unique--;
                    }
                    l++;
                }
                // Every character has frequency >= k
                if (unique == target && unique == countK) {
                    maxi = max(maxi, r - l + 1);
                }
                r++;
            }
        }
        return maxi;
    }
};