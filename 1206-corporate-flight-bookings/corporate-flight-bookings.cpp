class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> diff(n+1, 0);

        for(auto &seats : bookings){
            int L = seats[0];
            int R = seats[1];
            int x = seats[2];

            diff[L-1] += x;
            if(R < n){
                diff[R] -= x;
            }
        }
        vector<int> result(n, 0);
            int cum_Sum = 0;
            for(int i=0;i<n;i++){
                cum_Sum += diff[i];
                result[i] = cum_Sum;
            }
        return result;
    }
};