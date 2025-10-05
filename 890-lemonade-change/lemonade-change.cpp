class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_cnt = 0;
        int ten_cnt = 0;
        for(auto bill : bills){
            if(bill == 5) five_cnt++;
            else if(bill == 10){
                if(five_cnt > 0){
                    five_cnt--;
                    ten_cnt++;
                }
                else return false;
            }
            else{
                if(ten_cnt > 0 && five_cnt > 0){
                    ten_cnt--;
                    five_cnt--;
                }
                else if(five_cnt >= 3){
                    five_cnt -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};