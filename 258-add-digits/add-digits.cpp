class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        while(num > 9){
            int sum = 0;
            int temp = num;
            while(temp > 0){
                sum += temp%10;
                temp/=10;
            }
            num = sum;
        }
        return num;
    }
};