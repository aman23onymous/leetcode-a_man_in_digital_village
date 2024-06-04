class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> rep(26,0);
        for(int i=0;i<s.size();i++){
            if(rep[s[i]-97]==1) return s[i];
            rep[s[i]-97]++;
        }
        return 'a';
    }
};