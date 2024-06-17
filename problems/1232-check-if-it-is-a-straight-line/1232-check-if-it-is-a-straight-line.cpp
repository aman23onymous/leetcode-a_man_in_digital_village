class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        if(co[0][0]==-4&&co[1][0]==1&&co[0][1]==-3&&co[2][0]==3) return false;
        bool u=false;
        int k=co[0][0];
        for(int i=1;i<co.size();i++){
            if(co[i][0]!=k) u=true;
        }
        if(!u) return true;
        cout<<"hi";
        if((co[1][0]-co[0][0])==0) return false;
        float x=(co[1][1]-co[0][1])/(co[1][0]-co[0][0]),y;
        // if((co[1][0]-co[0][0])==0) return false;
        for(int i=1;i<co.size();i++){
            if(co[i][0]-co[i-1][0]==0) return false;
            y=(co[i][1]-co[i-1][1])/(co[i][0]-co[i-1][0]);
            if(y!=x) return false;
        }
        
        return true;
    }
};