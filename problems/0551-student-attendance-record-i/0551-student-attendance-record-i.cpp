class Solution {
public:
    bool checkRecord(string s) {
        int i=0;
        int a=0,l=0;
        while(s[i]!='\0'){
            if(s[i]=='P') l=0;
            else if(s[i]=='A'){
                l=0;
                a++;
            }
            else l++;
            if(l>2) return false;
            i++;
        }
        if(a>=2) return false;
        return true;
    }
};