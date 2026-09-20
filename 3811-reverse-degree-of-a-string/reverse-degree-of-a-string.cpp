class Solution {
public:
    int reverseDegree(string s) {
        int x=0;
        for(int i=0;i<s.size();i++){
            x+=(i+1)*(26-(s[i]-'a'));
        }
        return x;
    }
};