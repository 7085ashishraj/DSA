class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<int> &vis,int &source, int &destination){
        vis[source] = true;
        for(auto &it: graph[source]){
            if(!vis[it]){
                dfs(graph, vis, it ,destination);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int>vis(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);

        }
        dfs(graph, vis, source, destination);
        if(vis[destination] == false) return false;
        return true;
        
    }
};