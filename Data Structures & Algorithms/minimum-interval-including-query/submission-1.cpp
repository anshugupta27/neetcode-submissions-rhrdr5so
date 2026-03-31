class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> queries_index;
        vector<int> finalAns(queries.size(),0);
        for (int i = 0 ; i < queries.size() ; i++) {
            queries_index.push_back({queries[i],i});
        }
        sort(queries_index.begin(), queries_index.end());
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        int intervalsPtr = 0, queriesPtr = 0;
        while (queriesPtr < queries_index.size()) {
            int query = queries_index[queriesPtr][0];
            while (intervalsPtr < intervals.size() && query >= intervals[intervalsPtr][0]) {
                int range = intervals[intervalsPtr][1] - intervals[intervalsPtr][0] + 1;
                pq.push({range, intervals[intervalsPtr][1]});
                intervalsPtr++;
            }
            while (pq.size() && pq.top()[1] < query) pq.pop();
            if (pq.size()) finalAns[queries_index[queriesPtr][1]] = pq.top()[0];
            else finalAns[queries_index[queriesPtr][1]] = -1;
            queriesPtr++;

        }
        return finalAns;
    }
};
