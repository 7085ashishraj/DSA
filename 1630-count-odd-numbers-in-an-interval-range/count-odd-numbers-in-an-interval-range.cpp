class Solution {
public:
    int countOdds(int low, int high) {
        int odd_no_UptoHigh = (high + 1)/2; //will calculate the odd number upto high

        //calculating odd upto low-1

        int odd_no_Uptolow = low / 2;

        return (odd_no_UptoHigh - odd_no_Uptolow);


    }
};