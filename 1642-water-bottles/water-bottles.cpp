class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int Empty_bottles = numBottles;
        while(Empty_bottles >=  numExchange){
            int new_bottles = Empty_bottles / numExchange;
            result += new_bottles;
            Empty_bottles = new_bottles + (Empty_bottles % numExchange);
        }
        return result;
    }
};