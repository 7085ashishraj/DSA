class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //make adjacency list
        vector<vector<int>> adj(n); //u->{nbr1, nbr2};
        vector<int> inDegree(n, 0);
        vector<bool> suspicious(n, false);

        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        //BFS
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            //go to curr node's nbr and decrease krdo ooska indegree and mark that suspicious
            for(int &nbr : adj[curr]){
                inDegree[nbr]--;
                if(!suspicious[nbr]){
                    q.push(nbr);
                    suspicious[nbr] = true;
                }
            }
        }
        //make result vector
        vector<int> result;
        bool canNotRemove = false;
        for(int i=0;i<n;i++){
            if(suspicious[i] && inDegree[i] > 0){
                //we can't return anything as it is attacked by outsiders... direct return avl vector as it is
                canNotRemove = true;
                break;
            }
            if(!suspicious[i]){
                result.push_back(i);
            }
        }
        if(canNotRemove){
            vector<int> vec(n); // 0 1 2 3 .... n-1
            for(int i=0;i<n;i++){
                vec[i] = i;
            }
            return vec;
        }
        return result;
    }
};