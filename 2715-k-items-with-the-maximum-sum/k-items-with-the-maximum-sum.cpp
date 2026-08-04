class Solution {
public:
    int kItemsWithMaximumSum(int no, int nz, int numN, int k) {
        //int maxiSum = 0;
        // if(numOnes + numZeros > k){
        //     if(numOnes == k){
        //         maxiSum = numOnes;
        //     }else{
        //         while(numOnes != k){
        //             numOnes - 1;
        //         }
        //         maxiSum = numOnes;
        //     }
        // }
        if(no + nz >= k){
            if(k < no) return k;
            else return no;
        } else{
            return 2 * no + nz - k;
        }
        return -1;
    }
};