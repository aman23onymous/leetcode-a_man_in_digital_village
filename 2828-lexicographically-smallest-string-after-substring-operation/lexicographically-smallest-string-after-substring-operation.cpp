class Solution {
public:
    string smallestString(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') continue;
            int j=i;
            while(j<s.size() and s[j]!='a'){
                s[j]--;
                j++;
            }
            return s;
        }
        s[s.size()-1]='z';
        return s;
    }
};