class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector <vector<int>> v(n,vector<int>(n));
        int minr=0,maxr=n-1,minc=0,maxc=n-1,k=1;
        while(minr<=maxr&&minc<=maxc){
            for(int i=minc;i<=maxc;i++){
                v[minr][i]=k;
                k++;
            }
            minr++;
            for(int j=minr;j<=maxr;j++){
                v[j][maxc]=k;
                k++;
            }
            maxc--;
            for(int i=maxc;i>=minc;i--){
                v[maxr][i]=k;
                k++;
            }
            maxr--;
            for(int j=maxr;j>=minr;j--){
                v[j][minc]=k;
                k++;
            }
            minc++;
        }
        return v;
    }
};