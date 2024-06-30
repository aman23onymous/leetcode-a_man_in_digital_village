class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for(int i=1;i<travel.size();i++) travel[i]+=travel[i-1];
        int p=0,ppos=0;
        for(int i=0;i<garbage.size();i++){
            int k=0;
            for(int j=0;j<garbage[i].size();j++) if(garbage[i][j]=='P') k++;
            if(i>0&&k>0){
                p+=travel[i-1];
                if(ppos>0) p-=travel[ppos-1];
                ppos=i;
            }
            if(k>0) p+=k;
        }
        int g=0,gpos=0;
        for(int i=0;i<garbage.size();i++){
            int k=0;
            for(int j=0;j<garbage[i].size();j++) if(garbage[i][j]=='G') k++;
            if(i>0&&k>0){
                g+=travel[i-1];
                if(gpos>0) g-=travel[gpos-1];
                gpos=i;
            }
            if(k>0) g+=k;
        }
        int m=0,mpos=0;
        for(int i=0;i<garbage.size();i++){
            int k=0;
            for(int j=0;j<garbage[i].size();j++) if(garbage[i][j]=='M') k++;
            if(i>0&&k>0){
                m+=travel[i-1];
                if(mpos>0) m-=travel[mpos-1];
                mpos=i;
            }
            if(k>0) m+=k;
        }
        return p+g+m;
    }
};