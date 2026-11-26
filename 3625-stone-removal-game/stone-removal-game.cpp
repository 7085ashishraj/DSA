class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int cnt = 0;
        while(n >= take){
            n -= take;
            take--;
            cnt++;
        }
        return cnt % 2;
    }
};