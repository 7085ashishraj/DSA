class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        unordered_set< int> lower, upper;
        for(char c: word){
            if(islower(c)) lower.insert(c);
            else if(isupper(c)) upper.insert(c);
        }

        int cnt = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            if(lower.count(c) && upper.count(toupper(c)))
                cnt++;
        }
        return cnt;
    }
};