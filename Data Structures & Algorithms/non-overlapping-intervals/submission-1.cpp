class Solution {
public:
    static bool comp (vector<int> &a, vector<int> &b) {
        if (a[1] == b[1]) return a[0] < b[0] ;
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int prev = 0, count = 0;
        for (int next = 1 ; next < intervals.size() ; next++) {
            if (intervals[prev][1] <= intervals[next][0]) {
                count++;
                prev = next;
            }
        }
        return intervals.size() - count - 1;

    }
};
