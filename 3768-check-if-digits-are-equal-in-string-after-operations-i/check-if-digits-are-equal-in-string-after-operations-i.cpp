class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length()>2){
            string res = "";
            for(int i=0;i<s.length()-1;i++){
                int d1 = s[i]-'0';
                int d2 = s[i+1] - '0';
                int sum = (d1 + d2) % 10;
                res += to_string(sum);
            }
            s = res;
        }
        return s[0]==s[1];
    }
};