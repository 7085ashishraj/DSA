class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        //storing for sum and frequency(key ->value)
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1; //can be edge case
        int cnt = 0;
        for(int x : arr){
            sum+=x;
            if(mp.find(sum - k) != mp.end()){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};