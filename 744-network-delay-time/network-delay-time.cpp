class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //building adjacency list
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }

        //min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        //maintain a distance vector and apply dijkstra
        vector<int> dist(n+1, 1e9);

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis >  dist[node]) continue;

            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
        
    }
};