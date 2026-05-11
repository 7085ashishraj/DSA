class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> diff(n,0);

        for(auto& query : queries){
            int L = query[0];
            int R = query[1];
            int x = 1;

            diff[L] += x;
            if(R+1 < n){
                diff[R+1] -= x;
            }
        }

        //cummulative sum
        vector<int> result(n,0);
        int cumSum = 0;
        for(int i=0;i<n;i++){
            cumSum += diff[i];
            result[i] = cumSum;
        }

        for(int i=0;i<n;i++){
            if(result[i] < nums[i]) return false;
        }
        return true;
        
    }
};