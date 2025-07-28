class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sumOfFactors = 0;
        for(int i=1;i<sqrt(num);i++){
            if(num%i==0) sumOfFactors += i;
        }
        for(int i=sqrt(num);i>=1;i--){
            if(num%i==0) sumOfFactors += num/i;
        }
        if(sumOfFactors - num == num) return true;
        else return false;
    }
};