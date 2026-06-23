class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {

        int M = r - l + 1;

        if (n == 1)
            return M;

        vector<int> up(M + 1, 1);
        vector<int> down(M + 1, 1);

        vector<int> nextUp(M + 1);
        vector<int> nextDown(M + 1);

        for (int len = 2; len <= n; len++) {

            long long prefixDown = 0;

            for (int val = 1; val <= M; val++) {
                nextUp[val] = prefixDown;
                prefixDown =(prefixDown + down[val]) % MOD;
            }

            long long suffixUp = 0;

            for (int val = M; val >= 1; val--) {
                nextDown[val] = suffixUp;
                suffixUp =(suffixUp + up[val]) % MOD;
            }

            up.swap(nextUp);
            down.swap(nextDown);
        }

        long long ans = 0;

        for (int i = 1; i <= M; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return ans;
    }
};