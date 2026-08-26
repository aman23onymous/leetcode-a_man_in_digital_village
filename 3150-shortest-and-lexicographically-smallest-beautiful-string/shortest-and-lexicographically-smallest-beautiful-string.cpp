class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ms="z";
        int c1=0,ln=100000000;
        for(int i=0,j=0;i<s.size();i++){
            c1+=(s[i]-'0');
            while(c1>=k){
                c1-=(s[j]-'0');
                j++;
            }
            cout<<c1<<i<<" ";
            if(c1==k-1 and j>0 and ln>i-j+2){
                ln=i-j+2;
                ms=s.substr(j-1,ln);
            }
            else if(c1==k-1 and j>0 and ln==i-j+2 and ms>s.substr(j-1,ln)) ms=s.substr(j-1,ln);
        }
        if(ms=="z") return "";
        return ms;
    }
};