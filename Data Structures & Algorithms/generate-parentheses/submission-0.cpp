class Solution {
public:
    void generateParenthesisUtil(int open, int close, int n, string str, vector<string> &finalAns) {
        if (open < close) return;
        if (open > n || close > n) return ;
        if (open+close == 2*n ) {
            finalAns.push_back(str);
            return;
        }

        generateParenthesisUtil(open+1, close, n, str+"(", finalAns);

        generateParenthesisUtil(open, close+1, n, str+")", finalAns);

    }
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        string str = "";
        vector<string> finalAns;
        generateParenthesisUtil(open, close, n, str, finalAns);
        return finalAns;
    }
};
