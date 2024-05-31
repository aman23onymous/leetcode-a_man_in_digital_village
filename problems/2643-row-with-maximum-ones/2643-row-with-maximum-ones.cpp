class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=-1;
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) c++;
            }
            m=max(m,c);
        }
         vector<int> r;
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) c++;
            }
            if(c==m){
                r.push_back(i);
                r.push_back(m);
                return r;
            }
        }
        return r;
    }
};