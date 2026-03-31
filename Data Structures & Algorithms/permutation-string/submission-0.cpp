class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        unordered_map<char,int> mp;
        for (int i = 0 ; i < s1.length() ; i++) {
            mp[s1[i]]++;
        }
        int count = mp.size();
        int windowStartIndex = 0, windowEndIndex = 0;
        for (int i = 0 ; i < s1.length()-1; i++) {
            if (mp.find(s2[i]) != mp.end()) {
                mp[s2[i]]--;
                if (mp[s2[i]] == 0) count--;
            }
        }
        windowEndIndex = s1.length()-1;
        while (windowEndIndex < s2.length()) {
            if (mp.find(s2[windowEndIndex]) != mp.end()) {
                mp[s2[windowEndIndex]]--;
                if (mp[s2[windowEndIndex]] == 0) count--;
            }
            if (count == 0) return true;
            if (mp.find(s2[windowStartIndex]) != mp.end()) {
                mp[s2[windowStartIndex]]++;
                if (mp[s2[windowStartIndex]] == 1) count++;
            }
            windowStartIndex++;
            windowEndIndex++;
        }
        return false;
    }
};
