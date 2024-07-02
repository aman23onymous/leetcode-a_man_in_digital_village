class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        vector<vector<bool>> x(201,vector<bool>(201,0));
        for(int k=0;k<circles.size();k++){
            for(int i=0;i<=200;i++){
                for(int j=0;j<=200;j++){
                    if(!x[i][j]){
                        if(pow(circles[k][0]-i,2)+pow(circles[k][1]-j,2)<=pow(circles[k][2],2)) x[i][j]=1;
                    }
                }
            }
        }
        int c=0;
        for(int i=0;i<=200;i++){
            for(int j=0;j<=200;j++){
                if(x[i][j]) c++;
            }
        }
        return c;
    }
};