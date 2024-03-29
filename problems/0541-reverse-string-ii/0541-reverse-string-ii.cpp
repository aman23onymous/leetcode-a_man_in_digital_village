class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=k){
            if((k>(s.size()-i))&&(i%(2*k)==0)){
                for(int j=i,l=s.size()-1;j<=l;j++,l--){
                    swap(s[j],s[l]);
                }
            }
            else if(i%(2*k)==0){
                for(int j=i,l=i+k-1;j<=l;j++,l--){
                    swap(s[j],s[l]);
                }
            }
        }
        return s;
    }
};