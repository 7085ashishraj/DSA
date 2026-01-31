class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;

        vector<int>A(26,0); // for string p
        vector<int>B(26,0); // for string s

        for(char ch : p){
            A[ch - 'a']++; 
        }
        for(int i=0;i<p.size();i++){
            B[s[i]- 'a']++; //filling current window
        }

        if(A == B) res.push_back(0);

        for(int i=p.size();i<s.size();i++){
            B[s[i]-'a']++;
            B[s[i - p.size()] - 'a']--; //Remove prv char
            if(A==B) res.push_back(i-p.size()+1);
        }
        
        return res;
    }
};