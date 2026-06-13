class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto it : words){
            int sum = 0;
            for(int i=0;i<it.length();i++){
                sum += weights[it[i]-'a'];
            }
            int modulo = sum % 26;
            char frm_last = 'z' - modulo;//for getting reverse character from z(z->a)
            ans.push_back(frm_last);
        }
        return ans;
    }
};