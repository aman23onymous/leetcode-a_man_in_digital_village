class Solution {
public:
    string removeOuterParentheses(string s) {
        int k=0;
        int n=s.size();
        int b[n];
        for(int i=0;i<n;i++){
            if(s[i]=='(') b[i]=k++;
            else b[i]=--k;
        }
        string y="";
        for(int i=0;i<n;i++){
            if(b[i]) y.push_back(s[i]);
        }
        return y;
    }
};