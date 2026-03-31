class Solution {
public:
// https://www.youtube.com/watch?v=amnrMCVd2YI
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize != 0) return false;
        map<int,int> mp;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i = 0; i < hand.size() ; i++) {
            mp[hand[i]]++;
        }
        for (auto it: mp) {
            pq.push(it.first);
        }
        while (pq.size()) {
            int top = pq.top();
            for (int i = 0 ; i < groupSize ; i++) {
                if (mp[top+i] > 0) mp[top+i]--;
                if (mp[top+i] == 0) {
                   
                    if (top+i != pq.top()) {
                         cout << top << ", " << i << "\n";
                        return false;
                    }
                    pq.pop();
                    mp.erase(top+i);
                }
                
            }
        }
        return true;
    }
};
