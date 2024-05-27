class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& mat) {
        // vector<vector<int>> p;
        for(int i=0;i<mat[0].size();i++){
            int mx=-1;
            for(int j=0;j<mat.size();j++){
                mx=max(mx,mat[j][i]);
            }
            for(int j=0;j<mat.size();j++){
                if(mat[j][i]==-1) mat[j][i]=mx;
            }
        }
        return mat;
    }
};