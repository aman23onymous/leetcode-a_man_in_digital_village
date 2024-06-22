class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string m="";
        for(int i=1;i<s.size();i++) m=m+"0";
        m=m+"1";
        int j=0;
        for(int i=0;i<s.size();i++) if(s[i]=='1') j++;
        for(int i=0;i<j-1;i++) m[i]='1';
        return m;
    }
};