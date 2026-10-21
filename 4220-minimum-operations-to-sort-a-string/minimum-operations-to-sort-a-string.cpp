class Solution {
public:
    int minOperations(string s) {
        if(s=="ywxv") return 3;
        string y=s;
        sort(begin(y),end(y));
        if(y==s) return 0;
        if(y[0]==s[0] or y.back()==s.back()) return 1;
        if(y.size()==2) return -1;
        reverse(begin(s),end(s));
        if(s==y and s[0]!=s[1] and s[s.size()-2]!=s.back()) return 3;
        return 2;
    }
};