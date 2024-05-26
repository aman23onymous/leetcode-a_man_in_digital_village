class Solution {
public:
    int matrixScore(vector<vector<int>>& mat) {
        if(mat.size()==1&&mat[0].size()==1) return 1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][0]==0){
                for(int j=0;j<mat[0].size();j++){
                    mat[i][j]=1-mat[i][j];
                }
            }
        }
        for(int i=1;i<mat[0].size();i++){
            int cnt=0;
            for(int j=0;j<mat.size();j++){
                if(mat[j][i]==1) cnt++;
            }
            if(cnt<=mat.size()/2){
                for(int j=0;j<mat.size();j++){
                    mat[j][i]=1-mat[j][i];
                }
            }
        }
        int s=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                s=s+mat[i][j]*pow(2,mat[0].size()-j-1);
            }
        }
        return s;
    }
};