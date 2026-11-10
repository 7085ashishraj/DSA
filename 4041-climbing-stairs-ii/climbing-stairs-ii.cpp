class Solution {
public:
    typedef long long ll;
    ll climb(int i,int n, vector<int> &costs, vector<ll> &dp){
        if (i == n) return 0;
        if(dp[i] != -1) return dp[i];

        ll ans = LLONG_MAX;
        for(int jump = 1; jump <= 3; jump++){
            int nxt = i + jump;

            if(nxt <= n){
                ans = min(ans, 1ll * costs[nxt] + 1ll * jump * jump + climb(nxt, n, costs, dp));
            }
        }
        return dp[i] = ans;
    }
    ll climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0); // make 1-indexed
        //dp[i] = min cost to reach step n starting from i
        vector<ll> dp(n+1, -1);
        return climb(0, n, costs, dp);
        
    }
};