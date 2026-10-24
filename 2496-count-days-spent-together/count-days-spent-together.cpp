class Solution {
public:

    int findDay(string date, vector<int>&cumSum){
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3));

        int total = cumSum[month - 1] + day;
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> cumSum(13,0);
        cumSum[1] = 31;
        for(int i=2;i<=12;i++){
            cumSum[i] = days[i-1] + cumSum[i-1];
        }

        int aliceArr = findDay(arriveAlice, cumSum);
        int aliceLeave = findDay(leaveAlice, cumSum);
        int bobArr = findDay(arriveBob, cumSum);
        int bobLeave = findDay(leaveBob, cumSum);

        int commonDays = min(aliceLeave, bobLeave) - max(aliceArr, bobArr) + 1;

        if(commonDays < 0) return 0;
        else return commonDays;



        
    }
};