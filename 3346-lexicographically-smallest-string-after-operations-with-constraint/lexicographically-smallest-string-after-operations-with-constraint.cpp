class Solution {
public:
    string getSmallestString(string s, int k) {
        for(int i=0;i<s.size() and k>0;i++){
            int l=s[i]-'a';
            int kk=max(l-k,0);
            
            if((l+k>=26 and (l-kk>26-l)) or (kk!=0 and l+k>=26)){
                s[i]='a';
                k-=(26-l);
            }
            else{
                s[i]='a'+kk;
                k-=(l-kk);
            }
        }
        return s;
    }
};