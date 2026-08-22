class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int pdt = 1;
        while(n > 0){
            int ld = n % 10;
            sum += ld;
            pdt *= ld;
            n/=10;
        }
        int totalSum = (sum + pdt);
        if(original % totalSum == 0) return true;
        else return false;
    }
};