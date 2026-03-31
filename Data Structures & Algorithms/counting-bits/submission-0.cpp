class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> finalAns;
        finalAns.push_back(0);
        for (int i = 1; i <= n ; i++) {
            int countOne = 0, temp = i;
            while (temp != 0) {
                if (temp & 1) countOne++;
                temp = temp >> 1;
            }
            finalAns.push_back(countOne);
        }
        return finalAns;
    }
};
