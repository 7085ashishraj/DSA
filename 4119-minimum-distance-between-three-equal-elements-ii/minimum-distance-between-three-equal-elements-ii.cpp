class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        int dis = INT_MAX;

        for(int k=0;k<n;k++){
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3){
                vector<int> &v = mp[nums[k]];
                //calculating dis
                //2*(k-1);
                int size = v.size();
                int i = v[size - 3];
                int k = v[size - 1];

                dis = min(dis, 2*(k-i));
            }
            
        }
        if(dis == INT_MAX) return -1;
        return dis;
        
    }
};