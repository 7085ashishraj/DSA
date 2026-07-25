class Solution {
public:
    int maxProduct(int n) {
        int lar = 0, seclar = 0;
        while(n>0){
            int d = n % 10;
            if(d >= lar){
                seclar = lar;
                lar = d;
            }else if(d > seclar){
                seclar = d;
            }
            n /= 10;
        }
        return lar * seclar; //largest nikalo secLargest nikalo then multiply both
    }
};