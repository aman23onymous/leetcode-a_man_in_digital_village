class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        vector<string> s(n-2,"");
        for(int i=2;i<n;i++){
            int x=i;
            while(x>0){
            if(x&1) s[i-2]+="1";
            else s[i-2]+="0";
            x/=2;
        }
        }
        for(int a=0;a<n-2;a++){
            int i=0,j=s[a].size()-1;
            while(i<=j){
            if(s[a][i]!=s[a][j]) return false;
            i++,j--;
        }
        }
        return true;
    }
};