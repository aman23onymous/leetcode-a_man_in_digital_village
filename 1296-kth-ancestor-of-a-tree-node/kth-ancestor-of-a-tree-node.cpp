class TreeAncestor {
public:
    vector<vector<int>> bin;
    TreeAncestor(int n, vector<int>& par) {
        bin.resize(50010,vector<int>(20,0));
        for(int i=0;i<n;i++){
            bin[i][0]=par[i];
        }
        for(int i=1;i<18;i++){
            for(int j=0;j<n;j++){
                if(1+bin[j][i-1]) bin[j][i]=bin[bin[j][i-1]][i-1];
                else bin[j][i]=-1;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=20;i>=0 and node!=-1;i--){
            if(k&(1<<i))node=bin[node][i];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */