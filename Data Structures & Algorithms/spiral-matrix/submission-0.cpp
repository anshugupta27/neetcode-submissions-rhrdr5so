class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> finalAns;
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = col-1, k = 0, l = row -1 ;
        while (i <= l && k <= j) {
        int itr = k;
        while (i <= l && k <= j && itr <= j) {
            finalAns.push_back(matrix[i][itr]);
            itr++;
        }
        i++;
        itr = i;
        while (i <= l && k <= j &&  itr <= l) {
            finalAns.push_back(matrix[itr][j]);
            itr++;
        }
        j--;
        itr = j;
        while (i <= l && k <= j && itr >= k) {
            finalAns.push_back(matrix[l][itr]);
            itr--;
        }
        l--;
        itr = l;
        while (i <= l && k <= j && itr >= i) {
            finalAns.push_back(matrix[itr][k]);
            itr--;
        }
        k++;
        }

        for (int i = 0 ;  i< finalAns.size() ; i++) cout << finalAns[i] << ", " ;
        return finalAns;
    }
};
