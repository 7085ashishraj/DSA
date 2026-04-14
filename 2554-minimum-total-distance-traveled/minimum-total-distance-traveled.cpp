class Solution {
public:
    typedef long long ll;

    ll solve(int robot_idx, int fac_pos_idx, vector<int>& robot, vector<int> &positions, vector<vector<ll>> &t){
        if(robot_idx >= robot.size()){
            return 0;
        }

        if(fac_pos_idx >= positions.size()){
            return 1e12;
        }

        if(t[robot_idx][fac_pos_idx] != -1){
            return t[robot_idx][fac_pos_idx];
        }

        ll take = abs(robot[robot_idx] - positions[fac_pos_idx]) + solve(robot_idx + 1, fac_pos_idx+1, robot, positions, t);
        ll skip =  solve(robot_idx, fac_pos_idx+1, robot, positions, t);

        return t[robot_idx][fac_pos_idx] =  min(take, skip);

    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        //sort both robot and factory to avoid taking maximum distance
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));

        int m = robot.size();

        // expand factory positions to avoid tracking
        vector<int> positions;
        for(int i=0; i<factory.size() ; i++){
            int limit = factory[i][1];
            int pos = factory[i][0];

            for(int j=0;j<limit;j++){
                positions.push_back(pos);
            }

            
        }

        int n = positions.size();
        vector<vector<ll>> t(m+1, vector<ll>(n+1, -1));
        //return solve
        return solve(0,0,robot, positions, t);
        
    }
};