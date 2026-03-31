class Solution {
public:
     static bool comp (pair<int,int> &a, pair<int,int>&b) {
        if (a.first == b.first) return a.second < b.second;
        if (a.first > b.first) return true;
        return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for (int i = 0 ; i < nums.size() ; i++) {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> v ;
        vector<int> finalAns;
        for (auto it : mp) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0 ; i < k && i < v.size(); i++) {
            finalAns.push_back(v[i].second);
        }
        return finalAns ;
    }
};
