class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();

        while(n > k){
            string res = "";
            for(int i = 0; i < n; i += k){
                int sum = 0;
                for(int j = i; j < n && j < i + k; j++){
                    sum += s[j] - '0';
                }
                res += to_string(sum);
            }
            s = res;
            n = s.length();
        }
        return s;
    }
};