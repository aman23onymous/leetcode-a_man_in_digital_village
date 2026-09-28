class Solution {
public:
    int maxDepth(string s) {
        int k=0,mx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') k++;
            else if(s[i]==')') k--;
            mx=max(mx,k);
        }
        return mx;
    }
};