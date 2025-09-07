class Solution {
public:
    int getNext(int n){
        int total_sum = 0;
        while(n>0){
            int digit = n % 10;
            total_sum += digit * digit;
            n/=10;
        }
        return total_sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);

        while(fast != slow){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }
};