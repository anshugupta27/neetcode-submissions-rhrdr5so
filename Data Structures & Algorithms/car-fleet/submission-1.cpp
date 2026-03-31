class Solution {
public:
    int greatestOnRight (vector<double> &v) {
        stack<double> stk;
        int n = v.size();
        vector<int> finalAns;
        int fleet = 0;
        for (int i = n-1 ; i >= 0 ; i--) {
            if (!stk.size()) {
                finalAns.push_back(n);
            } else if (stk.size() && stk.top() >= v[i]) {
                finalAns.push_back(stk.top());
                fleet++;

            } else {
                while (stk.size() && stk.top() < v[i]) stk.pop();
                if (!stk.size()) finalAns.push_back(n);
                else {
                    finalAns.push_back(stk.top());
                    fleet++;
                }
            }
            stk.push(v[i]);
        }
        return n-fleet;

    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> posSpeed;
        vector<double> v;
        for (int i = 0 ; i < position.size() ; i++) {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.begin(), posSpeed.end());
        for (int i = 0 ; i < position.size() ; i++) {
            int pos = posSpeed[i].first;
            int velocity = posSpeed[i].second;
            double diffDis = target - pos;
            double time = diffDis/velocity;
            v.push_back(time);
        }
        return greatestOnRight(v);
    }
};
