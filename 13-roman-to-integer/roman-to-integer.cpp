class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> roman_val = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        for(int i=0;i<s.length()-1;i++){
            if(roman_val[s[i]]<roman_val[s[i+1]]){
                ans -= roman_val[s[i]];
            }
            else ans += roman_val[s[i]];
        }

        return ans + roman_val[s[s.length()-1]];
    }
};