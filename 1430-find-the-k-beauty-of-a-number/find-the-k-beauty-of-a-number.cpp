class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int n = str.size();
        int cnt = 0;
        
        for(int i=0; i<=n-k; i++){
            int val = stoi(str.substr(i,k));

            if(val != 0 && num % val == 0) cnt++;
        }
        return cnt;   
    }
};