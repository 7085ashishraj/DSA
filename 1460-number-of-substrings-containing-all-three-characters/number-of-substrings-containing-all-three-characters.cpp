class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int cnt = 0;
        vector<int> mp(3,0);
        
        int l = 0;
        int r = 0;
        while(r < n){
            char ch = s[r];
            mp[ch - 'a']++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                cnt += (n - r);
                mp[s[l] - 'a'] --;
                l++;
            }
            r++;
        }
        return cnt;
        
    }
};