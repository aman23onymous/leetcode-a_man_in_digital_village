class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size()*matrix[0].size();
        vector<int> p;
        int i=0,minr=0,minc=0,maxr=matrix.size()-1,maxc=matrix[0].size()-1;
    while(minr<=maxr&&minc<=maxc){
            for(int j=minc;j<=maxc&&i<n;j++,i++){
                p.push_back(matrix[minr][j]);
            }
            minr++;
            for(int j=minr;j<=maxr&&i<n;j++,i++){
                p.push_back(matrix[j][maxc]);
            }
            maxc--;
            for(int j=maxc;j>=minc&&i<n;j--,i++){
                p.push_back(matrix[maxr][j]);
            }
            maxr--;
            for(int j=maxr;j>=minr&&i<n;j--,i++){
                p.push_back(matrix[j][minc]);
            }
            minc++;
        }
        //if(m!=n) p.pop_back();
        return p;
    }
};