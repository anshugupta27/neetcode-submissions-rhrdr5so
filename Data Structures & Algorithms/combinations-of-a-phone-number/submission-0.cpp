class Solution {
public:
    void letterCombinationsRecursion (string digits, vector<string> &phoneDialPad, string ans, int itr, vector<string> &finalAns) {
        if (itr >= digits.length()) {
            finalAns.push_back(ans);
            return;
        }
        char buttonPressed = digits[itr];
        string letters = phoneDialPad[buttonPressed-'0'];
        for (int i = 0 ; i < letters.length() ; i++) {
            ans += letters[i];
            letterCombinationsRecursion (digits, phoneDialPad, ans, itr+1, finalAns);
            ans.pop_back();

        }


    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> phoneDialPad = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>finalAns;
        letterCombinationsRecursion (digits, phoneDialPad, "", 0, finalAns);
        return finalAns;
        
    }
};
