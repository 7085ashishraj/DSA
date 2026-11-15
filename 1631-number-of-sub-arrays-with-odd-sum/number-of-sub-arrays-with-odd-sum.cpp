class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ecnt = 1 ;
        int ocnt = 0 ;
        int sum = 0 ;
        int ans = 0 ;
        int mod = 1e9 +7;
        for(int num : arr){
            sum+=num;
            if(sum%2==0){
                ecnt++;
                ans = (ans+ocnt)%mod;
            } else{
                ocnt++;
                ans = (ans+ecnt)%mod;
            }
        }
        return ans;
    }
};