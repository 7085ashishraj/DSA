class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0, mini = 0;
        for(int ele : gain) mini = mini + ele, maxi = max(maxi,mini);
        return maxi;
    }
};