class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int j = 0;
        unordered_map<char, int> mp;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])==0 || mp[s[i]]<j){
                mp[s[i]] = i;
                maxLen = max(maxLen,i-j+1);
            }else{
                j = mp[s[i]] + 1;
                mp[s[i]] = i;
            }
        }
        return maxLen;
    }
};