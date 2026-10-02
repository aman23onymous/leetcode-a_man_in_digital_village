class Solution {
public:
    void stree(vector<string> &l,string s,int i,int n){
        if(s.size()>2*n||i<0) return;
        if(s.size()==2*n&&i==0){
            l.push_back(s);
            return;
        }
        stree(l,s+"(",i+1,n);
        if(i>0) stree(l,s+")",i-1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> l;
        string s="";
        cout<<s<<n;
        stree(l,s,0,n);
        return l;
    }
};