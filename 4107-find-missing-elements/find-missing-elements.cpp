class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min_ele = *min_element(nums.begin(), nums.end());
        int max_ele = *max_element(nums.begin(), nums.end());
        //vector<int> res;
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> res;

        for (int i = min_ele; i <= max_ele; i++) {
            if (st.find(i) == st.end()) {
                res.push_back(i);
            }
        }
        return res;
    }
};