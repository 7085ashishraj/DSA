class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {
        vector<int> count(26,0);
        for(char c : s){
            count[c - 'a']++;
        }

        int max1 = 0;
        int max2 = 0;

        for(int i=0;i<26;i++){
            if(isVowel('a' + i)){
                max1 = max(max1 , count[i]);
            }
            else max2 = max(max2 , count[i]);
        }

        return max1 + max2;
    }
};