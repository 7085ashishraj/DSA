class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int result = INT_MAX;
        for(int i=0; i<n; i++){
            if(words[i] == target){
                int straight_dis = abs(i-startIndex);
                int cir_dis = (n - straight_dis);
                result = min({result, straight_dis, cir_dis});
            }
        }
        if(result == INT_MAX) return -1;
        else return result;

        
    }
};