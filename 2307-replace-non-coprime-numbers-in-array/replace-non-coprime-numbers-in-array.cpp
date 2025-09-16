class Solution {
public:
    long long findGcd(long long x , long long y){
        if(y==0 ) return x;
        return findGcd(y,x%y);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            long long y = nums[i];
            while(ans.size()>0 && findGcd(y,ans.back())>1){
                long long x = ans.back();
                ans.pop_back();
                y = x*y/findGcd(x,y);
            }
            ans.push_back(y);
        }
        return ans;
    }
};