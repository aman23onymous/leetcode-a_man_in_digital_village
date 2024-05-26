class Solution {
public:
    int diff(char a,char b){
        int d=a-b;
        if(d>=0) return d;
        return -d;
    }
    int scoreOfString(string s) {
        int a=0;
        for(int i=0;i<s.size()-1;i++){
            a+=diff(s[i],s[i+1]);
        }
        return a;
    }
};