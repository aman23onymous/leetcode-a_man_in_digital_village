class Solution {
public:
    int countAsterisks(string s) {
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='|') a++;
            if(s[i]=='*'&& a%2==0) b++;
        }
        return b;
    }
};