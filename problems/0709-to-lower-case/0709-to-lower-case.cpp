class Solution {
public:
    string toLowerCase(string s) {
        int i=0;
        while(s[i]!='\0'){
            if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
            i++;
        }
        return s;
    }
};