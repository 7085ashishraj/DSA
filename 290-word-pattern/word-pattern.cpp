class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // will use stringstream to split the s and then find its length
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        if(pattern.length() != words.size()) return false;
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for(int i=0;i<pattern.length();i++){
            char ch1 = pattern[i];
            string s2 = words[i];

            if(mp1.count(ch1)){
                if(mp1[ch1] != s2){
                    return false;
                }
            }

            if(mp2.count(s2)){
                if(mp2[s2] != ch1){
                    return false;
                }
            }
            mp1[ch1] = s2;
            mp2[s2] = ch1;
        }
        return true;

    }
};