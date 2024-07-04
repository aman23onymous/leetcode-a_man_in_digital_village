class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int v=0,c=0,h=0;
        for(int i=0;i<s.size();i++){
            v=0,c=0;
            for(int j=i;j<s.size();j++){
                if(s[j]==97||s[j]==101||s[j]==105||s[j]==111||s[j]==117) v++;
                else c++;
                if(v==c&&(v*c)%k==0) h++;
            }
        }
        return h;
    }
};