class Solution {
public:
bool isVowel(char c){
    return c == 'a' ||  c=='e' || c=='i' || c=='o' || c=='u';
}
    int maxVowels(string s, int k) {
        int n = s.length();
        int max_vowels = 0;
        int curr_vowels = 0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                curr_vowels++;
            }
        }
        max_vowels = curr_vowels;
        for(int i=k;i<n;i++){
            if(isVowel(s[i])){
                curr_vowels++;
            }
            if(isVowel(s[i-k])){
                curr_vowels--;
            }
            max_vowels = max(curr_vowels, max_vowels);
        }
        return max_vowels;
    }
};