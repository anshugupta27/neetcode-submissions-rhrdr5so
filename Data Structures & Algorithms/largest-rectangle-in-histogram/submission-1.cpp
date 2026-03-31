class Solution {
public:
    vector<int> minOnLeft(vector<int>& heights) {
        stack<int> stk;
        vector<int> finalAns ;
        for (int i = 0 ; i < heights.size() ; i++) {
            if (!stk.size()) finalAns.push_back(-1);
            else if (stk.size() && heights[stk.top()] < heights[i]) finalAns.push_back(stk.top());
            else {
                while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
                if (!stk.size()) finalAns.push_back(-1);
                else finalAns.push_back(stk.top());
            }
            stk.push(i);
        }
        return finalAns;

    }
    vector<int> minOnRight(vector<int>& heights) {
                stack<int> stk;
        vector<int> finalAns ;
        int n = heights.size();
        for (int i = n-1 ; i >= 0 ; i--) {
            if (!stk.size()) finalAns.push_back(n);
            else if (stk.size() && heights[stk.top()] < heights[i]) finalAns.push_back(stk.top());
            else {
                while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
                if (!stk.size()) finalAns.push_back(n);
                else finalAns.push_back(stk.top());
            }
            stk.push(i);
        }
        reverse(finalAns.begin(), finalAns.end());
        return finalAns;

    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> minLeft = minOnLeft(heights);
        vector<int> minRight = minOnRight(heights);
        int n = heights.size(), maxArea = 0;
        for (int i = 0 ; i < minLeft.size() ; i++) cout << minLeft[i] << ", ";
        cout << "\n";
        for (int i = 0 ; i < minRight.size() ; i++) cout << minRight[i] << ", ";
        for (int i = 0 ; i < n ; i++) {
            int height = heights[i];
            int width = abs(minLeft[i] - minRight[i])-1;
            maxArea = max (maxArea, height*width);
        }
        return maxArea;
    }
};
