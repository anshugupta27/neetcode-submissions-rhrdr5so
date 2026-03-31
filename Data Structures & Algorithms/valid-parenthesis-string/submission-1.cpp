class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == '(') {
                maxOpen++;
                minOpen++;
            } else if (s[i] == ')') {
                maxOpen--;
                minOpen--;
            } else{
                maxOpen++;
                minOpen--;
            }
            if (maxOpen < 0) return false;
            else if (minOpen < 0) {
                minOpen = 0;
            }
        }
        return minOpen == 0;
    }
};
