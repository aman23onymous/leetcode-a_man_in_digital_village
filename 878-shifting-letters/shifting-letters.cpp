class Solution {
public:
    string shiftingLetters(string s, vector<int>& sf) {
        sf[s.size()-1]%=26;
        for(int i=s.size()-2;i>=0;i--){
            sf[i]+=sf[i+1];
            sf[i]%=26;
        }
        for(int i=0;i<s.size();i++){
            int t=s[i]-'a';
            t=(t+sf[i]+26)%26;
            s[i]=t+'a';
        }
        return s;
    }
};