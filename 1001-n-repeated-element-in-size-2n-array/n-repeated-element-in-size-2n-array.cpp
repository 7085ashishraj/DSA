class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        //int cnt = 0;
        int n = nums.size()/2;
        map<int,int>mp;
        for(int num_val : nums){
            mp[num_val]++; //increment each count(frequency)
        }
        for( auto const &ele : mp){
            if(ele.second == n) return ele.first;
        }
        return -1;
    }
};