class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        vector<int> diff(n, 0);

        for (auto& query : shifts) {
            int L = query[0];
            int R = query[1];
            int x = query[2];

            if (x == 1) { // forward shift
                diff[L] += x;
                if (R + 1 < n) {
                    diff[R + 1] -= x;
                }
            } else { // backward shift
                diff[L] -= 1;
                if (R + 1 < n) {
                    diff[R + 1] += 1;
                }
            }
        }
        // cummulative sum
        for (int i = 1; i <n; i++) {
            diff[i] += diff[i - 1];
        }
        // converting the text
        for (int i = 0; i < n; i++) {
            int shift = diff[i] % 26;
            if (shift < 0) {
                shift += 26;
            }

            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
        }
        return s;
    }
};