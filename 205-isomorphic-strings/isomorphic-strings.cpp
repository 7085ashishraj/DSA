class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char> mp1; // s->t compare for mapping char
        unordered_map<char, char> mp2; // t->s compare for mapping char

        for(int i=0;i<s.length();i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if(mp1.count(ch1)){ //mapping s->t
                if(mp1[ch1] != ch2) return false;
            }

            if(mp2.count(ch2)){ //mapping t->s
                if(mp2[ch2] != ch1) return false;
            }
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};