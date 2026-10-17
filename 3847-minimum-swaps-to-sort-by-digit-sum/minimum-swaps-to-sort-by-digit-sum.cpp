class Solution {
public:
    int calcDigitSum(int n){
        int sum = 0;
        while(n > 0){
            sum += (n % 10);
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>afterSort(nums);

        sort(afterSort.begin(), afterSort.end(), [&](int a, int b){
            int digitSum1 = calcDigitSum(a);
            int digitSum2 = calcDigitSum(b);

            if(digitSum1 != digitSum2) return digitSum1 < digitSum2;

            return a < b;
        });

        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            int expctdVal = afterSort[i];
            int currVal = nums[i];

            if(currVal == expctdVal) continue;

            int expctdIdx = mp[expctdVal];
            nums[i] = expctdVal;
            nums[expctdIdx] = currVal;

            //update idx in map
            mp[expctdVal] = i;
            mp[currVal] = expctdIdx;

            cnt++;
        }
        return cnt;    
    }
};