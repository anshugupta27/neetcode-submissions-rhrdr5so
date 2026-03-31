class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // iterate col and check if target[same_col] that el
        vector<int> potential_rows;

        for (int i = 0 ;  i< triplets.size() ; i++) {
            potential_rows.push_back(i);
        }
        for (int i = 0 ; i < target.size() ; i++) {
            int tar = target[i];
            vector<int> temp;
            for (int j = 0 ; j < potential_rows.size() ; j++) {
                if (triplets[potential_rows[j]][i] <= tar) temp.push_back(potential_rows[j]);
            }
            potential_rows = temp;
        }
        // for (int i = 0 ; i < potential_rows.size() ; i++) {
        //     cout << potential_rows[i] << "\n";
        //     for (int j = 0 ; j < triplets[0].size() ; j++) {
        //         max
        //     }
        // }
        for (int i = 0 ; i < triplets[0].size() ; i++) {
            int maxVal = -1;
            for (int j = 0 ; j < potential_rows.size() ; j++) {
                maxVal = max (maxVal, triplets[potential_rows[j]][i]);
            }
            if (maxVal != target[i]) return false;

        }
        return true;
    }
};
