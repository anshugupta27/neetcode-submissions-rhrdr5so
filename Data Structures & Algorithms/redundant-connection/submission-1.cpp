class Solution {
public:
    bool isCycle (int node, int parent, vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1;
        for (auto it: adj[node]) {
            if (!visited[it]) {
                if (isCycle(it, node, adj, visited)) return true;
            } else if (parent != it) {
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        
        for (int i = 0 ; i < n ; i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            adj[first].push_back(second);
            adj[second].push_back(first);
            vector<int>visited(n+1,0);
            if(isCycle (first, -1, adj, visited)) return edges[i];
        }
        return {};
    }
};
