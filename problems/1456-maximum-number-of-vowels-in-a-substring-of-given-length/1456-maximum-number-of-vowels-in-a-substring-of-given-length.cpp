class Solution {
public:
    int maxVowels(string s, int k) {
        int i=1,j=k,m=0,p=0;
        for(int i=0;i<k;i++) if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') p++;
        m=p;
        i=1;
        while(j<s.size()){
            if(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u') p--;
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u') p++;
            m=max(m,p);
            i++,j++;
        }
        return m;
    }
};