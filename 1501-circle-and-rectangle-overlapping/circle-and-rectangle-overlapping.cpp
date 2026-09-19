class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int Xi;
        int Yi;

        if(x1 > xCenter){
            Xi = x1;
        }
        else if(x2 < xCenter){
            Xi = x2;
        }
        else{
            Xi = xCenter;
        }

        if(y1 > yCenter){
            Yi = y1;
        }
        else if(y2 < yCenter){
            Yi = y2;
        }
        else{
            Yi = yCenter;
        }
        //(xi, yi) ------- (xCenter, yCenter)
        return sqrt((Xi - xCenter)*(Xi - xCenter) + (Yi - yCenter)*(Yi - yCenter)) <= radius;
        
    }
};