class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>>adj(n);
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> distance(n, INT_MAX);
        for (int i = 0 ; i < flights.size() ; i++) {
            int startPoint = flights[i][0];
            int dropPoint = flights[i][1];
            int cost = flights[i][2];
            adj[startPoint].push_back({dropPoint, cost});
        }
        pq.push({src, 0, 0});
        while (pq.size()) {
            auto front = pq.top();
            pq.pop();
            int parentNode = front[0];
            int parentDistance = front[1];
            int parentStops = front[2];
            for (auto neighbour: adj[parentNode]) {
                int neighbourNode = neighbour[0];
                int neighbourDistance = neighbour[1];
                if (parentStops > k) continue;
                if (neighbourDistance + parentDistance < distance[neighbourNode]) {
                    distance[neighbourNode] = neighbourDistance + parentDistance;
                    pq.push({neighbourNode, distance[neighbourNode], parentStops+1});
                }
            }
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
        
    }
};
