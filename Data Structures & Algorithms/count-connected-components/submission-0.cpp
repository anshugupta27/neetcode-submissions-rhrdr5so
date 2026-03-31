class Solution {
public:
    void  dfs(int node, vector<vector<int>>& adj, vector<int>&visited) {
        visited[node] = 1;
        for (auto it: adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int component = 0;
        vector<int>visited(n,0);
        vector<vector<int>> adj(n);
        for (int i = 0 ; i < edges.size() ; i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        for (int i = 0 ; i < n ; i++) {
            if (!visited[i]) {
                component++;
                dfs(i, adj, visited);
            }
        }
        return component;

    }
};
