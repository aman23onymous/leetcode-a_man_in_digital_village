class Solution {
public:
    bool checkString(string s) {
        int i=0,j=s.size()-1;
        while(i<s.size() and s[i]=='a') i++;
        while(j>=0 and s[j]=='b') j--;
        if(i==s.size() or j<0) return 1;
        return i>j;
    }
};