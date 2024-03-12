class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        vector<string> m;
        // float slope;
        int n= p.size();
        if(n==1||n==2) return n;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                string line="";
                // if(p[j][0]!=p[i][0]) cout<<float(p[j][1]-p[i][1])/float(p[j][0]-p[i][0])<<" ";
                if(p[j][0]==p[i][0]){
                    line+=to_string(9999999999);
                    line+=to_string(p[i][0]);
                }
                else {
                    if(float(p[j][1]-p[i][1])!=0) line+=to_string(float(p[j][1]-p[i][1])/float(p[j][0]-p[i][0]));
                    line+="x+";
                    if (float(p[i][1]*p[j][0]-p[i][0]*p[j][1])/float(p[j][0]-p[i][0])!=0) line+=to_string(float(p[i][1]*p[j][0]-p[i][0]*p[j][1])/float(p[j][0]-p[i][0]));
                }
                m.push_back(line);
                line="";
            }
        }
        sort(m.begin(),m.end());
        int max=1,res=0;
        for(int i=0;i<m.size()-1;i++){
            cout<<m[i]<<"  "<<m[i+1]<<endl;
            if(m[i]==m[i+1]) max++;
            else max=1;
            if(max>res) res = max;
        }
        return (1+pow(8*res+1,0.5))/2;
    }
};