class Solution {
public:
    int reverseBits(int n) {
        if(n==0) return 0; //base case
        int result = 0;
        for(int i=1;i<=32;i++){
            result <<= 1; //result me ek left shift karke make place, so that we can put a lsb from n
            result = result | (n &1); //append in result
            n>>=1; 
        }
        return result;
    }
};