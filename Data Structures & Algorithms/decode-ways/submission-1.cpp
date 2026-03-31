class Solution {
public:
    bool isValid(string s, int start, int end) {
        if (start > end || s[start] == '0' || end-start+1 > 2) return false;
        string temp = s.substr(start, end-start+1);
        if (stoi(temp) > 26) return false;
        return true;

    }
    void numDecodingsUtil(string s, int start, vector<string> v, int &countWays) {
        if (start == s.length() ) {
            countWays++;
            return;
        }

        for (int end = start ; end < s.length() ; end++) {
            if (isValid(s, start, end)) {
                v.push_back(s.substr(start, end-start+1));
                numDecodingsUtil (s, end+1, v, countWays);
                v.pop_back();
            }
        }
    }
    int numDecodings(string s) {
        vector<string> v;
        int countWays = 0;
        numDecodingsUtil(s, 0, v, countWays);
        return countWays;
    }
};
