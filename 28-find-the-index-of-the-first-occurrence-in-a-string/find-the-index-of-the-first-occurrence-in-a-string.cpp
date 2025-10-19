class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = (haystack.length()-needle.length());

        for(int i=0;i<=l;i++){
            string x = haystack.substr(i,needle.length());
            if(x==needle) return i;
        }
        return -1;
    }
};