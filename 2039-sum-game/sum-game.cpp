class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftSum = 0;
        int rightSum = 0;

        int leftQnCount = 0;
        int rightQnCount = 0;

        for(int i=0; i<n; i++){
            if(num[i] == '?'){
                if(i < n/2){
                    leftQnCount++;
                } else{
                    rightQnCount++;
                }
            }else{
                if(i < n/2){
                    leftSum += num[i] - '0';
                } else{
                    rightSum += num[i] - '0';
                }
            }
        }
        int totalQnCount = leftQnCount + rightQnCount;
        if(totalQnCount % 2 == 1){
            return true;
        }

        int left = leftSum + 4.5*leftQnCount;
        int right = rightSum + 4.5*rightQnCount;

        if(left == right) return false;
        return true;
    }
};