class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector <int> v(128,1000);
        for(int i=0;i<s.size();i++){
            char b=s[i];
            int h=(int)b;
            if(v[h]==1000) v[h]=(s[i]-t[i]);
            else if(v[h]!=(s[i]-t[i])) return false;
        }
        vector <int> p(128,1000);
        for(int i=0;i<s.size();i++){
            char b=t[i];
            int h=(int)b;
            if(p[h]==1000) p[h]=(t[i]-s[i]);
            else if(p[h]!=(t[i]-s[i])) return false;
        }
        return true;
    }
};