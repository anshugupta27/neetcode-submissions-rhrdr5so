class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for (int i = 0 ; i < points.size() ; i++) {
            auto coordinate = points[i];
            int x = coordinate[0];
            int y = coordinate[1];
            int distance = (x * x) + (y * y) ;
            if (pq.size() >= k && distance < pq.top().first) 
            {
                pq.pop();
                pq.push({distance, {x, y}});
            } else if (pq.size() < k) pq.push({distance, {x, y}});
        }
        vector<vector<int>> finalAns;
        while (pq.size()) {
            auto top = pq.top();
            pq.pop();
            vector<int> coord;
            coord.push_back(top.second.first);
            coord.push_back(top.second.second);
            finalAns.push_back(coord);
        }
        return finalAns;
    }
};
