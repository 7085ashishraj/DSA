class Solution {
public:

    void dfs(vector<vector<int>> &Graph, vector<bool>&visited, int source, int destination){
        visited[source] = true;
        for(int i : Graph[source]){
            if(visited[i] == false){
                dfs(Graph, visited, i, destination);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> Graph(n);
        vector<bool> visited(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
        dfs(Graph, visited, source, destination);
        if(visited[destination] == false) return false;
        return true;
    }
};