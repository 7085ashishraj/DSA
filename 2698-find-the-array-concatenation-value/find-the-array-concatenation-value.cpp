class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long concatValue = 0;
        vector<string> mod;
        for(int i=0;i<nums.size();i++){
            mod.push_back(to_string(nums[i]));
        }
        int m = 0;
        int n = mod.size()-1;
        while(m < n){
            concatValue += stoll(mod[m] + mod[n]);
            m++;
            n--;
        }
        if(m == n){
            concatValue += stoll(mod[m]);

        }
        return concatValue;
    }
};