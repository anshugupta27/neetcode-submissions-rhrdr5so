class Solution {
public:
    int maxFreq(unordered_map<char,int> &mp) {
        int maxCount = 0;
        for(auto it: mp) {
            maxCount = max(maxCount, it.second);
        }
        return maxCount;

    }
    int characterReplacement(string s, int k) {
        int windowStartIndex = 0, windowEndIndex = 0, maxWidth = 0;
        unordered_map<char, int> mp;
        while (windowEndIndex < s.length()) {
            mp[s[windowEndIndex]]++;
            int changes = windowEndIndex - windowStartIndex + 1 - maxFreq(mp);
            while (changes > k) {
                mp[s[windowStartIndex]]--;
                windowStartIndex++;
                changes = windowEndIndex - windowStartIndex + 1 - maxFreq(mp);
            }
            maxWidth = max(maxWidth, windowEndIndex - windowStartIndex + 1);
            windowEndIndex++;
        }
        return maxWidth;
    }
};
