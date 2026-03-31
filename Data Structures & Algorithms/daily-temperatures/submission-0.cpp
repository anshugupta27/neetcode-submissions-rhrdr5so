class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // greater on the right
        int n = temperatures.size(); 
        stack<int> stk;
        vector<int> finalAns;
        for (int i = n-1 ; i >= 0 ; i--) {
            if (stk.empty()) finalAns.push_back(0);
            else if (temperatures[stk.top()] > temperatures[i]) finalAns.push_back(abs(i-stk.top()));
            else {
                while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) stk.pop();
                if (stk.empty()) finalAns.push_back(0);
                else finalAns.push_back(abs(i-stk.top()));
            }

            stk.push(i);
        }
        reverse(finalAns.begin(), finalAns.end());
        return finalAns;
    }
};
