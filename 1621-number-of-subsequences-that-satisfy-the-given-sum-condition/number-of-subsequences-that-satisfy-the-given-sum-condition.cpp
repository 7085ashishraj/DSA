class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        const int MOD = 1e9 + 7;

        vector<int> power(n,1);
        power[0] = 1;
        for(int i=1;i<n;i++){
            power[i] = (power[i-1] * 2) % MOD;
        }

        int start = 0;
        int end = n - 1;

        long  long seq = 0;
        while(start <= end){
            if(nums[start] + nums[end] <= target){
                seq = (seq + power[end - start]) % MOD;
                start++;
            }else{
                end--;
            }
        }
        return static_cast<int>(seq);
    }
};