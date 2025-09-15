class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        //put the broken letters into a set
        unordered_set<char> broken(brokenLetters.begin(),brokenLetters.end());
        bool canType = true;
        //store count
        int cnt = 0;
        for(char c : text){
            if(c==' '){
                if(canType) cnt++;
                canType = true;
                
            }
            else if(broken.count(c)) canType = false;
        }
        if(canType) cnt++;
        return cnt;
    }
};