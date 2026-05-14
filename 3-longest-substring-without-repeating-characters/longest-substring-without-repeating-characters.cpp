class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> freq(256, 0);
        int i = 0;
        int j = 0;
        int maxi_len = 0;
        while(j<n){
            if(freq[s[j]] == 0){
                freq[s[j]]++;
                maxi_len = max(maxi_len, j-i+1);
                j++;
            }
            else{
                freq[s[i]]--;
                i++;
            }
        }
        return maxi_len;

        
    }
};