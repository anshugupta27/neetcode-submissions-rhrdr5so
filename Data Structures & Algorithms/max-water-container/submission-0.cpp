class Solution {
public:
    int maxArea(vector<int>& heights) {
      int left = 0, right = heights.size()-1, maxAns = INT_MIN;
      while (left < right) {
        int minHeight = min(heights[left], heights[right]);
        int width = right - left ; 
        maxAns = max(maxAns, minHeight*width);
        if (heights[left] < heights[right]) left++;
        else right--;
      }
      return maxAns;
    }
};
