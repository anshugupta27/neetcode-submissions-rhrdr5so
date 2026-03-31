class Solution {
public:
    int minDistanceRecursive (string word1, string word2, int index1, int index2) {
        
        // if (index1 >= word1.length() && index2 >= word2.length()) return 1;
        if (index1 >= word1.length() ) return word2.length() - index2 ;
        if (index2 >= word2.length()) return word1.length() - index1 ;

        if (word1[index1] == word2[index2]) {
             return minDistanceRecursive (word1, word2, index1+1, index2+1);
        }
        // if (word1[index1] != word1[index2]) {
            // replace
            return 1 + min ({minDistanceRecursive (word1, word2, index1+1, index2+1),
            // delete
            minDistanceRecursive (word1, word2, index1+1, index2),
            // insert
            minDistanceRecursive (word1, word2, index1, index2+1)});
        // }


    }
    int minDistance(string word1, string word2) {
        return minDistanceRecursive (word1, word2, 0, 0);
    }
};
