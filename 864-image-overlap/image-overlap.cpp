class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int mx=0,n=img1.size();
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                vector<vector<int>> b(n,vector<int>(n,0)),c(n,vector<int>(n,0));
                if(i<0){
                    for(int k=n-1;k+i>=0;k--){
                        for(int l=0;l<n;l++){
                            b[k+i][l]=img1[k][l];
                        }
                    }
                }
                else {
                    for(int k=0;k+i<n;k++){
                        for(int l=0;l<n;l++){
                            b[k+i][l]=img1[k][l];
                        }
                    }
                }
                if(j<0){
                    for(int k=n-1;k+j>=0;k--){
                        for(int l=0;l<n;l++){
                            c[l][k+j]=b[l][k];
                        }
                    }
                }
                else{
                    for(int k=0;k+j<n;k++){
                        for(int l=0;l<n;l++){
                            c[l][k+j]=b[l][k];
                        }
                    }
                }
                int bc=0;
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if(c[k][l] and img2[k][l]) bc++;
                    }
                }
                mx=max(bc,mx);
            }
        }
        return mx;
    }
};