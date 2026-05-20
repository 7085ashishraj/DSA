class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();

        //Brute-force
        vector<int> res(n, 0);
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int A_i = 0; A_i<=i; A_i++){
                for(int B_i = 0; B_i<=i; B_i++){
                    if(B[B_i] == A[A_i]){
                        cnt++;
                        break;
                    }
                }
            }
            res[i] = cnt;
        }
        return res;
        
    }
};