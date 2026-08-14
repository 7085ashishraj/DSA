class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int maxiLen = INT_MIN;
        while(r < n){
            mp[s[r]]++;
            while(mp[s[r]] > 2){
                mp[s[l]]--;
                l++;
            }
            r++;
            maxiLen = max(maxiLen, r-l);
        }
        return maxiLen;
    }
};