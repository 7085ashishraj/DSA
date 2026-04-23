class Solution {
public:
    typedef long long ll;
    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> res(n, 0);

        unordered_map<int, ll> indexSum; //nums[i]->sum of i's
        unordered_map<int, ll> indexCount; // nums[i]->freq

        //left to right
        for(int i=0; i<n; i++){
            ll freq = indexCount[nums[i]];
            ll sum =  indexSum[nums[i]];

            res[i] += freq * i - sum;
            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        indexSum.clear();
        indexCount.clear();

        //Right to left
        for(int i=n-1; i>=0; i--){
            ll freq = indexCount[nums[i]];
            ll sum =  indexSum[nums[i]];

            res[i] += sum - freq*i;
            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        return res;

    }
};