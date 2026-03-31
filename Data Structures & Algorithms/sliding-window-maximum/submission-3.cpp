class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int windowStartIndex = 0, windowEndIndex = 0;
        vector<int> finalAns;
        while (windowEndIndex < nums.size()) {
            while (dq.size() && nums[dq.back()] < nums[windowEndIndex]) {
                dq.pop_back();
            }
            while (dq.size() && dq.front() < windowEndIndex - k + 1) dq.pop_front();

            
             dq.push_back(windowEndIndex);
            if (windowEndIndex >= k-1)
            finalAns.push_back(nums[dq.front()]);

           
            windowEndIndex++;
        }
        return finalAns;
    }
};
