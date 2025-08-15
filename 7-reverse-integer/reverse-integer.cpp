class Solution {
public:
    int reverse(int x) {
        int reversed_no = 0;
        while(x!=0){
            if(reversed_no > INT_MAX/10 || reversed_no < INT_MIN/10){
                return 0;
            }
            reversed_no = (reversed_no * 10) + (x%10);
            x/=10;
            
        }
        return reversed_no;
    }
};