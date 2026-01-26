class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int n = arr.size();

        int min_diff = INT_MAX;

        for(int i=0;i<n-1;i++){
            int curr_diff = arr[i+1] - arr[i];
            if (curr_diff < min_diff){
                min_diff = curr_diff;
            } 
        }

        for(int i=0;i<n-1;i++){
            if(arr[i+1] - arr[i] == min_diff){
                result.push_back({arr[i],arr[i+1]});
            }
        }
        return result;
    }
};