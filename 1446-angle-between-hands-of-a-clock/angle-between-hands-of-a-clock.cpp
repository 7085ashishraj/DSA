class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_min = 6.0 * minutes;
        double angle_hour = 30.0 * (hour % 12) + 0.5 * minutes;
        double diff = abs(angle_hour - angle_min);

        return min(diff, 360.0 - diff); 
        
    }
};