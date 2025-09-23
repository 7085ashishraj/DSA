class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1; // for storing version1(after splitting)
        vector<int> v2; // for storing version2(after splitting)

        string temp = " ";

        //Iterating on version 1
        for(int i=0;i<version1.length();i++){
            if(version1[i]=='.'){
                v1.push_back(stoi(temp));
                temp = " ";
            }
            else{
                temp += version1[i];
            }
        }
        v1.push_back(stoi(temp));

        //Iterating on version 2
        temp = " ";
        for(int i=0;i<version2.length();i++){
            if(version2[i]=='.'){
                v2.push_back(stoi(temp));
                temp = " ";
            }
            else{
                temp += version2[i];
            }
        }
        v2.push_back(stoi(temp));

        int i = 0;
        int j = 0;
        while(i<v1.size() || j<v2.size()){
            int num1 = 0;
            int num2 = 0;

            if(i<v1.size()){
                num1 = v1[i];
            }

            if(j<v2.size()){
                num2 = v2[i];
            }

            if(num1 < num2) return -1;
            if(num1 > num2) return 1;

            i++;
            j++;
        }
        return 0;
    }
};