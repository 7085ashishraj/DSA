class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int, int> mp1, mp2;

        for(auto &ch : s){
            mp1[ch]++;
        }

        for(auto &ch : t){
            mp2[ch]++;
        }

       for(char ch = 'a'; ch<='z'; ch++){
        if(mp1[ch] != mp2[ch]){
            return false;
        }
       }
        return true;
    }
};