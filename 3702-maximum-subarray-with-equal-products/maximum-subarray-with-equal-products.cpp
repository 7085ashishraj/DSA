class Solution {
public:
    typedef long long ll;
    //calc gcd...
    ll findGCD(ll a, ll b){
        if(b==0) return a;
        return findGCD(b, a%b);
    }
    //calc lcm...
    ll findLCM(ll a, ll b){
        return a/findGCD(a, b) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        const ll LIMIT = 1e18;
        
        for(int i=0; i<n; i++){
            ll pdt = 1;
            ll gcd = 0;
            ll lcm = 1;

            for(int j = i; j<n; j++){

                //prevent product overflow
                if(pdt > LIMIT / nums[j]) break;

                pdt *= nums[j];

                //update gcd...
                if(gcd == 0) gcd = nums[j];
                else gcd = findGCD(gcd, nums[j]);

                //prevent lcm overfolw
                if(lcm > LIMIT /(nums[j] / gcd)) break;

                //update lcm
                lcm = findLCM(lcm, nums[j]);
                //check if equal...
                if(pdt == gcd * lcm) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};