class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        int n = k;
        while(st.count(n)){
            n+=k;

        }
        return n;
    }
};