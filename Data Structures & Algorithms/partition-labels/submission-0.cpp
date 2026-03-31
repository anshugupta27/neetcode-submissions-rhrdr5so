class Solution {
public:
    vector<int> partitionLabels(string s) {
        //store the last occurance of each char
        //
        unordered_map<char,int> lastCharOcc;
        for (int i = 0 ; i < s.length() ; i++) {
            if (lastCharOcc.find(s[i]) != lastCharOcc.end()) {
                lastCharOcc[s[i]] = max(lastCharOcc[s[i]], i);
            } else lastCharOcc[s[i]] = i;
        }
        int start = 0, substrLenEnd = 0;
        vector<int> ans;
        for (int i = 0 ; i < s.length() ; i++) {
            int lastOcc = lastCharOcc[s[i]];
            substrLenEnd = max(substrLenEnd, lastOcc);
            if (i == substrLenEnd) {
                //got one substr
                ans.push_back(substrLenEnd - start + 1);
                start = i+1;
                substrLenEnd = 0;
            }
        }
        return ans;
    }
};
