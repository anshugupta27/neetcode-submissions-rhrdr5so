class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // new interval can be merged with the last vec so pop 
        //the last and merge and push back again
        int lastItr = 0, i = 1;
        vector<vector<int>> finalAns;
        sort(intervals.begin(), intervals.end());
        finalAns.push_back(intervals[0]);
        while (i < intervals.size()) {
            if (finalAns[lastItr][0] <= intervals[i][0] && finalAns[lastItr][1] >= intervals[i][0]) {
                int tempx = min(finalAns[lastItr][0], intervals[i][0] );
                int tempy = max(finalAns[lastItr][1],  intervals[i][1] );
                finalAns.pop_back();
                finalAns.push_back({tempx, tempy});
            } else {
                finalAns.push_back(intervals[i]);
                lastItr++;
            }
            i++;

        }
        return finalAns;

        // no merging can be done so directly push the new interval
        
    }
};
