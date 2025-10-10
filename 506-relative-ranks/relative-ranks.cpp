class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> result(n);
        for(int i=0;i<n;i++){
            int rank = 1;
            for(int j=0;j<n;j++){
                if(score[j]>score[i]){
                    rank++;
                }
            }

            if(rank == 1) result[i] = "Gold Medal";
            else if(rank == 2) result[i] = "Silver Medal";
            else if(rank == 3) result[i] = "Bronze Medal";
            else result[i] = to_string(rank);
        } 
        return result;
    }
};