class Solution {
public:
bool w(int n){

    if(n==1) return 0;
    for(int i=2;i<=sqrt(n);i++) if(n%i==0) return 0;
    return 1;
}
int diagonalPrime(vector<vector<int>> m){
    int x=0;
    for(int i=0;i<m.size();i++){
        if(w(m[i][i])) x=max(x,m[i][i]);
        if(w(m[m.size()-i-1][i])) x=max(x,m[m.size()-1-i][i]);
    }
    return x;
}
        
    
};