class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> res(n, 0);
        res[0]= gain[0];
        int maxi = gain[0];

        for(int i=1;i<n;i++){
            res[i] = res[i-1]+gain[i];
            if(res[i] > maxi) maxi = res[i];
        }
        if(maxi > 0) return maxi;
        return 0;

    }
};