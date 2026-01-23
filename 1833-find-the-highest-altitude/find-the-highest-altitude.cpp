class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> pSum(gain.size());

        pSum[0] = gain[0];
        int maxGain = pSum[0];
        for(int i=1;i<gain.size();i++){
            pSum[i] = pSum[i-1] + gain[i];
            if(pSum[i]>maxGain ){
                maxGain = pSum[i];
            }
        }
        if(maxGain > 0 ) return maxGain;
        else return 0;
        
    }
};