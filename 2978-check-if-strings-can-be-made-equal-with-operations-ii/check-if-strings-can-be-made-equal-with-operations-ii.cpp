class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> evenCh(26,0);
        vector<int> oddCh(26,0);

        for(int i=0;i<s1.length();i++){
            if(i%2==0){ //for even idx
                evenCh[s1[i]-'a']++;
                evenCh[s2[i]-'a']--;
            }else{ //for odd idx
                oddCh[s1[i]-'a']++;
                oddCh[s2[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(evenCh[i]!=0 || oddCh[i]!=0){
                return false;
            }
        }
        return true;
    }
};