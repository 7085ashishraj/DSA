class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(int val : arr1){
            while(!st.count(val) && val > 0){
                st.insert(val);
                val/=10;
            }
        }

        int res = 0;
        for(int ele : arr2){
            while(!st.count(ele) && ele > 0){
                ele /= 10;
            }

            if(ele > 0){
                res = max(res, static_cast<int>(log10(ele) + 1));
            }
        }
        return res;   
    }
};