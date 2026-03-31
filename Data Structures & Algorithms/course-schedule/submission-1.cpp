class Solution {
public:
    bool dfs(int node, vector<int> &visited, vector<int> &pathVisited, int numCourses, vector<vector<int>>& adj) {
        visited[node] = 1;
        pathVisited[node] = 1;
        for (auto it: adj[node]) {
            if (!visited[it]) {
                if(dfs(it, visited, pathVisited, numCourses, adj)) return true;
            } else if (pathVisited[it]) return true;
        }
        pathVisited[node] = 0;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //cycle detection in directed graph
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (int i = 0 ; i < prerequisites.size() ; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0 ; i < numCourses ; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVisited, numCourses, adj)) return false;
            }
        }
        return true;
    }
};
