class Solution {
public:
    int numDistinctRecursion (string s, string t, int index, string subSeqStr) {
        if (index >= s.length()) {
            if (subSeqStr == t) return 1;
            return 0;
        }
        int isSubSeq = 0;
        subSeqStr += s[index];
        isSubSeq += numDistinctRecursion (s, t, index+1, subSeqStr);
        subSeqStr.pop_back();
        isSubSeq += numDistinctRecursion (s, t, index+1, subSeqStr);
        return isSubSeq;

    }
    int numDistinct(string s, string t) {
        string subSeqStr = "";
        return numDistinctRecursion (s, t, 0, subSeqStr);
        return 0;
    }
};
