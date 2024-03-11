class Solution {
public:
    string convert(string s, int numRows) {
        string p;
        char a[numRows][s.size()];
        for(int i=0;i<numRows;i+=1){
            for(int j=0;j<s.size();j++){
                a[i][j]='0';
            }
        }
        int m=0,i=0,col=0;
        while(m<s.size()){
            for(i=0;i<numRows&&m < s.size();i++){
                a[i][col]=s[m];
                m++;
            }
            col++;
            i-=2;
            while(i>0&&m < s.size()){
                a[i][col]=s[m];
                col++;
                i--;
                m++;
            }
        }
        for(int i=0;i<numRows;i+=1){
            for(int j=0;j<s.size();j++){
                if(a[i][j]!='0') p=p+a[i][j];
            }
        }
        return p;
    }
};
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if (numRows <= 1 || s.size() <= 1)
//             return s; // No change needed if numRows is 1 or less

//         vector<vector<char>> a(numRows, vector<char>(s.size(), ' ')); // Initialize 2D vector with spaces

//         int m = 0, col = 0, i = 0;
//         while (m < s.size()) {
//             for (i = 0; i < numRows && m < s.size(); ++i) {
//                 a[i][col] = s[m++];
//             }
//             --i;
//             ++col;
//             while (i > 1 && m < s.size()) { // For the diagonal traversal
//                 a[--i][col++] = s[m++];
//             }
//         }

//         // Form the string from the 2D array
//         string p;
//         for (int i = 0; i < numRows; ++i) {
//             for (int j = 0; j < s.size(); ++j) {
//                 if (a[i][j] != ' ')
//                     p.push_back(a[i][j]);
//             }
//         }

//         return p;
//     }
// };