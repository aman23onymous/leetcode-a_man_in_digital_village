class Solution {
public:
    int lengthOfLastWord(string s) {
        int k=0,l=s.size(),i=s.size()-1;
        if(i==0) return 1;
        if(s[i]==' '){
            while(s[i]==' '){
            i--;
        }
        }
        while(s[i]!=' '){
            if(i==0) return k+1;
            k++;
            i--;
        }
        return k;
    }
};