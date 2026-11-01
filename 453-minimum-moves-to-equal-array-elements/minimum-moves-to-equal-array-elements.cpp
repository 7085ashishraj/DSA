class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int miniEle = *min_element(nums.begin(),nums.end());
        long long reqSum = miniEle * n;
        long long total = accumulate(nums.begin(), nums.end(),0);
        return total - reqSum;

        
    }
};