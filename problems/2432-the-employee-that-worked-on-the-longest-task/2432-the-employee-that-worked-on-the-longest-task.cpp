class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        for(int i=logs.size()-2;i>=0;i-=1){
            logs[i+1][1]-=logs[i][1];
        }
        int m=-1,p;
        for(int i=0;i<logs.size();i++){
            if(m<logs[i][1]){
                m=logs[i][1];
                p=logs[i][0];
            }
            if(m==logs[i][1]){
                p=min(p,logs[i][0]);
            }
        }
        return p;
    }
};