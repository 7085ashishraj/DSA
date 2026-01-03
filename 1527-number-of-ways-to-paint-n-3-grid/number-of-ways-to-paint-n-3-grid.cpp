class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> t;

    // 12 possible first states in Ist row
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY",
                         "YRY", "GRY", "GYR",       "GRG", "GYG"};

    int solve(int n, int prev) {
        if (n == 0) {
            return 1;
        }

        if(t[n][prev] != -1){
            return (t[n][prev]);
        }

        int result = 0;
        string last = states[prev];

        for (int curr = 0; curr < 12; curr++) {
            if (curr == prev)
                continue;
            string currPatt = states[curr];
            bool conflict = false;
            // traversing each column to check last color character should not
            // same

            for (int col = 0; col < 3; col++) {
                if (currPatt[col] == last[col]) {
                    conflict = true;
                    break;
                }
            }
            if (!conflict)
                result = (result + solve(n - 1, curr)) % M;
        }

        return t[n][prev] = result;
    }
    int numOfWays(int n) {

        t.resize(n,vector<int>(12, -1));

        int result = 0;

        for (int i = 0; i < 12; i++) { // selecting Ist row
            // now remaining n-1 rows painting
            result = (result + solve(n - 1, i)) % M;
        }

        return result;
    }
};