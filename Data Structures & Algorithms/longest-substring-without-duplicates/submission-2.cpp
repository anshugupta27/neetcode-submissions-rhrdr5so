class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int startWindowIndex = 0, endWindowIndex = 0, maxLen = 0;
        unordered_map<char,int> charLastIndexMap;
       while(endWindowIndex < s.length()) {
            maxLen = max(maxLen, endWindowIndex - startWindowIndex);
            if (charLastIndexMap.find(s[endWindowIndex]) != charLastIndexMap.end()) {
                int index = charLastIndexMap[s[endWindowIndex]];
                if (index >= startWindowIndex ) {
                    startWindowIndex = index+1;
                    charLastIndexMap[s[endWindowIndex]] = endWindowIndex;
                } else {
                    charLastIndexMap[s[endWindowIndex]] = endWindowIndex;
                }
            }
            charLastIndexMap[s[endWindowIndex]] = endWindowIndex;
            endWindowIndex++;
        }
        maxLen = max(maxLen, endWindowIndex - startWindowIndex);
        return maxLen;
    }
};
