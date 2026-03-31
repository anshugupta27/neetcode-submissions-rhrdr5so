class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> time(1000,INT_MAX);
        vector<int> finalAns;
        for (int i = 0 ; i < intervals.size() ; i++) {
            int startTime = intervals[i][0];
            int endTime = intervals[i][1];
            int range = endTime - startTime + 1;
            for (int j = startTime ; j <= endTime ; j++) {
                time[j] = min(time[j], range);
            }
        }
        for (int i = 0 ; i < queries.size() ; i++) {
            int minTime = time[queries[i]] ;
            finalAns.push_back(minTime == INT_MAX ? -1 : minTime);
        }
        return finalAns;
    }
};
