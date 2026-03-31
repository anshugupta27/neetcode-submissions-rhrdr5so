class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> finalAns;
       int itr = 0;
        // case 1:
        // when start of newInterval is greater than the end of interval
        while (itr < intervals.size()) {
            if (newInterval[0] > intervals[itr][1]) 
            finalAns.push_back(intervals[itr]);
            else break;
            itr++;
        }
        //case 2:
        // end of the newInterval lies between start and end of the interval so merge them
        while (itr < intervals.size()) {
            if (newInterval[1] >= intervals[itr][0] ) {
                int tempx = min(intervals[itr][0], newInterval[0]);
                int tempy = max(intervals[itr][1], newInterval[1]);
                newInterval[0] = tempx;
                newInterval[1] = tempy;
            }
            else break;
            itr++;
        }
        finalAns.push_back(newInterval);

        //case 3:
        // start intervals > end of new Interval
        while (itr < intervals.size()) {
            finalAns.push_back(intervals[itr]);
            itr++;
        }
        return finalAns;
    }
};
