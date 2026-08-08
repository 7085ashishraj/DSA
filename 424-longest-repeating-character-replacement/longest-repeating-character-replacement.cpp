class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        vector<int> Freq(26,0);
        int mf = 0 ;
        int ml = 0 ;
        for(r = 0 ; r < n ; r++){
            Freq[s[r]-'A']++;
            mf = max(mf,Freq[s[r]-'A']);
            while((r-l+1)-mf > k){
                Freq[s[l]-'A']--;
                l++;
            }
            ml = max(ml,r-l+1);
        }
        return ml;
        
    }
};