class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftCnt = 0;
        int  rightCnt = 0; 
        int dash = 0;
        for(int i=0; i<moves.length(); i++){
            if(moves[i] == 'L') leftCnt++;
            else if(moves[i] == 'R') rightCnt++;
            else dash++;
        }
        return abs(leftCnt - rightCnt) + dash;
    }
};