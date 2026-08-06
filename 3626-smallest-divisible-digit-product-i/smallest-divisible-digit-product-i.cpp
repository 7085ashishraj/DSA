class Solution {
public:
    int solve(int n, int t){
        int orgNo = n;
        int pdt = 1;
        while(n > 0){
            int ld = n % 10;
            pdt *= ld;
            n/=10;
        }
        if(pdt % t == 0){
            return orgNo; 
        }
        return solve(orgNo+1, t);
    }
    int smallestNumber(int n, int t) {
        return solve(n, t);
    }
};