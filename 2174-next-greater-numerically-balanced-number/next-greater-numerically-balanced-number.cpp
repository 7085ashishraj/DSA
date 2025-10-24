class Solution {
    bool isBalanced(int x){
        if(x==0) return false;
        int count[10] = {0};
        int temp = x;

        while(temp>0){
            int digit = temp % 10;
            count[digit]++;
            temp/=10;
        }

        for(int d = 0;d < 10; d++){
            if(count[d]>0){
                if(count[d]!=d){
                    return false;
                }
            }
           
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        for(int i = n+1; ;i++) {
            if(isBalanced(i)){
                return i;
            }
        }
    }
};