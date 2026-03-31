class Solution {
public:
    bool isCycle (int node, int parent, vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1;
        for (auto it: adj[node]) {
            if (!visited[it]){
                if(isCycle(it, node, adj, visited))return true;
            } else if (parent != it) return true;
        }
        return false;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
         vector<int>visited(n,0);
        int component = 0;
        for (int i = 0 ; i < edges.size() ; i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }

        for (int i = 0 ; i < n ; i++) {
            
            int parent = -1;
            if(!visited[i]) {
                component++;
               if(isCycle(i, parent, adj, visited)) 
                   return false;
            }
           
            // if (component > 1) return false;
        }

        if (component > 1) return false;
        return true;
        

    }
};
