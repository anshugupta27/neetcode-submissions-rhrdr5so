class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //iterate the vec and concat the digits to form a no. and add 1 and again tokenize the no.
        long long num = 0, n = digits.size();
        vector<int> finalAns;
        for (int i = 0 ; i < digits.size() ; i++) {
            num += digits[i]*pow(10,n-i-1);
        }
        num = num + 1;
        cout << num;
        while(num > 0) {
            finalAns.push_back(num%10);
            num = num/10;
        }
        reverse(finalAns.begin(), finalAns.end());
        return finalAns;
        
    }
};
