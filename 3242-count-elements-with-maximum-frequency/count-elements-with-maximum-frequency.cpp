class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &ele : nums){
            mp[ele]++;
        }
        int maxFreq = 0;
        for(auto &ele : mp){
            maxFreq = max(maxFreq, ele.second);
        }
        int sum = 0;
        for(auto &ele : mp){
            if(ele.second == maxFreq){
                sum += ele.second;
            }
        }
        return sum;
    }
};