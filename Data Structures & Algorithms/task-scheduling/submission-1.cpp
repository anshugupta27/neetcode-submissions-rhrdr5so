class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for (int i = 0 ; i < tasks.size() ; i++) {
            mp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for (auto it:mp) {
            pq.push(it.second);
        }
        int time = 0;
        while (pq.size()) {
            int oneCycle = n+1, cycle = 0;
            vector<int> temp;
            for (int i = 0 ; i < oneCycle ; i++) {
                if (pq.size()) {
                    int topEle = pq.top();
                    pq.pop();
                    if (topEle > 1) temp.push_back(topEle-1);
                    cycle++;
                }
            }
            for (auto it:temp) {
                pq.push(it);
            }
            time += pq.empty() ? cycle : oneCycle ; 
        }
        return time;

    }
};
