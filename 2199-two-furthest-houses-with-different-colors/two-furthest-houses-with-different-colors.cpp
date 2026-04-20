class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = INT_MIN;
        for(int i=0;i<colors.size();i++){
           for(int j=0;j<colors.size();j++){
            if(colors[j] != colors[i]){
                ans = max(ans, abs(i-j));
            }
           }
        }
        if(ans == INT_MIN) return -1;
        else return ans;
    }
};