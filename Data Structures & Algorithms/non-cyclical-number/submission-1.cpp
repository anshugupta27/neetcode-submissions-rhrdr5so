class Solution {
public:
    vector<int> countZeros(string s) {
        int countZero = 0, countOne = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == '0') countZero++;
            else if (s[i] == '1') countOne++; 
        }
        return {countZero, countOne};

    }
    bool isHappy(int n) {
        // case 1: either check if all no. are 0 except one
        // case 2: do 1 iteration to get to second stage then then again check if all characters are zero except 1
       string str = to_string(n);
       map<string,int> mp;
       while (1) {
        if (mp.find(str) != mp.end()) return false;
        mp[str]++;
        vector<int> countVal = countZeros(str);
       if (countVal[1] == 1 &&  countVal[0] == str.length()-1) return true;
       
        int sumDigits = 0 ;
        for (int i = 0 ; i < str.length() ; i++) {
            sumDigits += (str[i] - '0')*(str[i] - '0');
        }
        cout << "sumDigits = " << sumDigits ;
        str = to_string(sumDigits);
       }
       
       
        return false;
    }
};