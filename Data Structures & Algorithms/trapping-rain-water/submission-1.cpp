class Solution {
public:
    vector<int> maxOnLeftHandler (vector<int>& heights) {
          int n = heights.size();
        vector<int> v;
        v.push_back(0);
        int maxVal = heights[0];
        for (int i = 1 ; i < n ; i++) {
            maxVal = max(maxVal, heights[i]);
            v.push_back(maxVal);
        }
        return v;
    }
        vector<int> maxOnRightHandler (vector<int>& heights) {
            int n = heights.size();
        vector<int> v(n,0);
        int maxVal = heights[n-1];
        for (int i = n-2 ; i >= 0 ; i--) {
            maxVal = max(maxVal, heights[i]);
            v[i] = maxVal;
        }
        return v;
    }
    int trap(vector<int>& heights) {
        vector<int> maxOnLeft = maxOnLeftHandler(heights);
        vector<int> maxOnRight = maxOnRightHandler(heights);
        int sum = 0 , n = heights.size();
        for (int i = 0 ; i < n ; i++) {
            int minWall = min(maxOnLeft[i], maxOnRight[i]);
            if (minWall > heights[i]) sum += minWall - heights[i];
        }
        return sum;
    }
};
