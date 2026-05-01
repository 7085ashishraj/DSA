class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        for(auto &passanger : trips){
            int p = passanger[0];
            int f = passanger[1];
            int t = passanger[2];

            diff[f] += p;
            diff[t] -= p;
        }

        int cum_sum  = 0;
        for(int i=0;i<1001;i++){
            cum_sum += diff[i];
            if(cum_sum > capacity) return false;
        }
        
        return true;
    }
};