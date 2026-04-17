class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while(num>0){
            int ld = num % 10;
            rev = rev*10+ld;
            num/=10;
        }
        return rev;

    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int result = INT_MAX;

        for(int i=0; i<n; i++){
            if(mp.count(nums[i])){
                result = min(result, i - mp[nums[i]]);
            }

            mp[reverse(nums[i])] = i;
        }

        return result == INT_MAX ? -1 : result;
        
    }
};