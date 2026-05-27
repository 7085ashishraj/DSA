class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> lastOcc(26,-1);
        vector<int> firstOcc(26,-1);

        for(int i=0;i<n;i++){
            if(islower(word[i])){
                lastOcc[word[i] - 'a'] = i;
            }
            else{
                if(firstOcc[word[i] - 'A'] == -1){
                    firstOcc[word[i] - 'A'] = i;
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<26;i++){
            if(lastOcc[i] != -1 && firstOcc[i] != -1 && lastOcc[i] < firstOcc[i]) cnt++;
        }
        return cnt;    
    }
};