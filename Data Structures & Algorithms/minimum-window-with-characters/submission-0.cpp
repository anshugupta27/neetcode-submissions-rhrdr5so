class Solution {
public:
    string minWindow(string s, string t) {
        int windowStartIndex = 0, windowEndIndex = 0, minWindow = INT_MAX;
        string minWindowStr = "";
        unordered_map<char,int> mp;
        for (int i = 0 ; i < t.length() ; i++) {
            mp[t[i]]++;
        }
        int count = mp.size();
        while (windowEndIndex < s.length()) {
            if (mp.find(s[windowEndIndex]) != mp.end()) {
                mp[s[windowEndIndex]]--;
                if (mp[s[windowEndIndex]] == 0) count--;
            }
            
            while (count == 0) {
                if (count == 0 && windowEndIndex - windowStartIndex + 1 < minWindow) {
                minWindow = windowEndIndex - windowStartIndex + 1;
                minWindowStr = s.substr(windowStartIndex, minWindow);
            }
                if (mp.find(s[windowStartIndex]) != mp.end()) {
                    mp[s[windowStartIndex]]++;
                    if (mp[s[windowStartIndex]] == 1) count++;
                }
                windowStartIndex++;
                
            }
            
           
            windowEndIndex++;
        }
        
        return minWindowStr;
    }
};
