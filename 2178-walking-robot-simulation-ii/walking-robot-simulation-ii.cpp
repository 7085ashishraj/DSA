class Robot {
public:
    int idx = 0;
    bool flag = false;
    vector<vector<int>> position;
    Robot(int width, int height) {
        //Bottom row(left->right) East(0)
        for(int x=0; x<width;x++){
            position.push_back({x,0,0});
        }

        //right column(bottom->top) North(1)
        for(int y=1;y<height;y++){
            position.push_back({width-1, y, 1});
        }

        //top-row(right->left) west(2)
        for(int x=width-2;x>=0;x--){
            position.push_back({x, height - 1, 2 });
        }

        //left column(top->bottom) south(3)
        for(int y=height - 2;y>0;y--){
            position.push_back({0,y,3});
        }

        //making first as South,  will handle East edge case seperately
        position[0][2] = 3;
    }
    
    void step(int num) {
        flag = true;
        idx = (idx + num) % position.size();
    }
    
    vector<int> getPos() {
        return {position[idx][0], position[idx][1]};
    }
    
    string getDir() {
        if(flag == false) return "East";
        int d = position[idx][2];
        if(d == 0) return "East";
        else if(d == 1) return "North";
        else if(d == 2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */