class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int m = -1;
        if (s1.size() == 1&&s2.size() == 1&&s3.size() == 1) {
            if(s1[0] != s2[0] || s2[0] != s3[0]) return -1;
            return 0;
        }
        if(s1[0] != s2[0] || s2[0] != s3[0]) return -1;
        if (s1.size() >= 1&&s2.size() >= 1&&s3.size() >= 1) {
            m = 0;
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i] || s2[i] != s3[i]) break;
                m++;
            }
            m=s1.size()+s2.size()+s3.size()-3*m;
        }
        return m;
    }
};