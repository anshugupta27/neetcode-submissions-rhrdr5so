class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0, high = s.length()-1;
        while (low <= high) {
            if (s[low] != s[high]) return false;
            low++, high--;
        }
        return true;

    }
    void partitionRecursion(string s, int index, vector<string>&ans, vector<vector<string>> &finalAns) {
        if (index >= s.length()){
             finalAns.push_back(ans);
             return ;
        }

        for (int i = 1 ; i <= s.length()-index ; i++) {
            string temp = s.substr(index, i);
            if (isPalindrome(temp))
            {
                ans.push_back(temp);
                partitionRecursion(s, index+i, ans, finalAns); 
                ans.pop_back();
            }
        }

    } 

    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> finalAns;
        partitionRecursion(s, 0, ans, finalAns);
        return finalAns;   

    }
};
