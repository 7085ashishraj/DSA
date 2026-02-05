class Solution {
public:
    char findTheDifference(string s, string t) {
        //string result = s+t;
        unordered_map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        for(char ch : t){
           mp[ch]--;
           if(mp[ch]<0) return ch; //if char freq becomes negative, just return that char
        }
        return ' ';
    }
};