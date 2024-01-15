class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();//NO. OF ROW
        int n=matrix[0].size();//NO. OF COLUMN
        vector<vector<int>> p(n,vector<int>(m));//MATRIX WITH OPPOSITE NO.S OF ROW AND COLUMN
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                p[i][j]=matrix[j][i];
            }
        }
        return p;
    }
};