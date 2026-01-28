class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int boats = 0;

        int start = 0;
        int end = n-1;
        while(start <= end){
            if(people[start] + people[end] <= limit){
                boats++;
                start++;
                end--;  //if pair found
            }else{
                boats++;
                end--;
            }
        }
        return boats;
    }
};