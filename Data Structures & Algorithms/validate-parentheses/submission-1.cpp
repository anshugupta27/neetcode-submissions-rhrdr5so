class Solution {
public:
    bool isOpeningBracket(char s) {
        if (s == '(' || s == '[' || s == '{') return true;
        return false;

    }
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0 ; i < s.length() ; i++) {
            if (isOpeningBracket(s[i])) stk.push(s[i]);
            else {
                if (!stk.size()) return false;
                char stkTop = stk.top();
                stk.pop();
                if (s[i] == ')' && stkTop != '(') return false;
                if (s[i] == '}' && stkTop != '{') return false;
                if (s[i] == ']' && stkTop != '[') return false;
            }
        }
        if (stk.size()) return false;
        return true;
    }
};
