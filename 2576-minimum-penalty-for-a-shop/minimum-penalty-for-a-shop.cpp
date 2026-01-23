class Solution {
public:
    int bestClosingTime(string customers) {
        //penalty if we close the shop at 'i'th hour = (no. of 'Y' >=i) + (no.of 'N' before 'i'th hour) 
    int n = customers.length();
    //N ka prefix sum
    vector<int> preNo(n+1);
    preNo[0] = 0;
    for(int i=0;i<n;i++){
        int Ncnt = 0;
        if(customers[i] == 'N'){
            Ncnt++;
        }
        preNo[i+1] = preNo[i] + Ncnt;
    }
    //Y ka suffix sum
    vector<int> sufSum(n+1);
    sufSum[n] = 0;
    for(int i=n-1;i>=0;i--){
        int Ycnt = 0;
        if(customers[i] == 'Y'){
            Ycnt++;
        }
        sufSum[i] = sufSum[i+1] + Ycnt;
    }

    int minPen = n;
    for(int i=0;i<=n;i++){
        preNo[i] += sufSum[i];
        int pen = preNo[i];
        minPen = min(minPen,pen);
    }

    for(int i=0;i<=n;i++){
        int pen = preNo[i];
        if(pen == minPen) return i;
    }

    return n;
        
    }
};