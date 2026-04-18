class Solution {
public:
    int rev(int num){
        int rev_num = 0;
        while(num > 0){
            int ld = num % 10;
            rev_num = rev_num * 10 + ld;
            num/=10;
        }
        return rev_num;
    }
    int mirrorDistance(int n) {
        return abs(n - rev(n));
        
    }
};