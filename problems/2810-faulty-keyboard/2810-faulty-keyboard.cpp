class Solution {
public:
    string finalString(string s) {
        string a="";
        int i=0,n=s.size();
        while(i<n){
            if(s[i]=='i'){
                reverse(a.begin(),a.end());
            }
            else a+=s[i];
            i+=1;
        }
        return a;
    }
};