class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> distance(n+1, INT_MAX);
        for (int i = 0 ; i < times.size() ; i++) {
            int startPoint = times[i][0];
            int endPoint = times[i][1];
            int time = times[i][2];
            adj[startPoint].push_back({endPoint, time});
        }
        pq.push({0,k});
        distance[k] = 0;
        while (pq.size()) {
            auto front = pq.top();
            int parentTime = front[0];
            int parentNode = front[1];
            pq.pop();
            for (auto neighbour: adj[parentNode]) {
                int neighbourNode = neighbour[0];
                int neighbourTime = neighbour[1];
                if (neighbourTime + parentTime < distance[neighbourNode]) {
                    distance[neighbourNode] = neighbourTime + parentTime;
                    pq.push({distance[neighbourNode], neighbourNode});
                }

            }
        }
        int minAns = INT_MIN;
        for (int i = 1 ; i <= n ; i++) minAns = max(minAns, distance[i]);
        return minAns == INT_MAX ? -1: minAns;

    }
};
