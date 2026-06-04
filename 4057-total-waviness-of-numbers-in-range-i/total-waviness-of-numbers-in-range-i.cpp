class Solution {
public:
    int check(int num){
        string s = to_string(num);
        int l = s.length();
        if(l<3) return 0;
        int cnt = 0;
        for(int i=1; i<=l-2; i++){
            if(s[i]>s[i-1] && s[i]>s[i+1]) cnt++;
            if(s[i]<s[i-1] && s[i]<s[i+1]) cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
            int cnt = 0;
            for(int i=num1;i<=num2;i++){
                cnt += check(i);
            }
            return cnt;
    }
};