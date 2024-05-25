class Solution {
public:
    int findLUSlength(string a, string b) {
        // If strings are identical, there is no uncommon subsequence
        if (a == b) return -1;
        
        // If strings are different, the LUS is the longer of the two strings
        // because it cannot be a subsequence of the other.
        return max(a.size(), b.size());
    }
};