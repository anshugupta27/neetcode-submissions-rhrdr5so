class Solution {
public:
    int getOperated(int firstNum, int secondNum, string token) {
        if (token == "+") return firstNum + secondNum;
        if (token == "*") return firstNum * secondNum;
        if (token == "-") return secondNum - firstNum  ;
        return secondNum / firstNum ;
    }
    int convertStrToNum(string num) {
        int temp = 0;
        bool isNegative = false;
        if (num[0] == '-') {
            num = num.substr(1, num.length()-1);
            isNegative = true;
        }
        for (int i = 0 ; i < num.length() ; i++) {
            temp = (temp * 10) + (num[i]-'0') ;
        }
        return isNegative ? -1 * temp : temp;

    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0 ; i < tokens.size() ; i++) {
            string num = tokens[i];
            if (num != "*" && num != "+" && num != "-" && num != "/" ) {
                stk.push(convertStrToNum(num));
            } else {
                int firstNum = stk.top();
                stk.pop();
                int secondNum = stk.top();
                stk.pop();
                stk.push(getOperated(firstNum, secondNum, tokens[i]));
            }
        }
        return stk.top();
    }
};
