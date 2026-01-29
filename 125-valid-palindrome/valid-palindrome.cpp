class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        //if(n==1) return true;
        string str = "";
        for(char c : s){
            if(isalnum(c)){
                str += tolower(c);
            }
        }
        int i = 0;
        int j = str.length()-1;
        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};