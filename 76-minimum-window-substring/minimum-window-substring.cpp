class Solution {
public:
    unordered_map<char,int>ma;
    unordered_map<char,int>mp;
    bool ch(){
        for(auto [x,y]:ma){
            if(y>mp[x])return 0;
        }
        return 1;
    }
    string minWindow(string s, string t) {
        int ml=1e9,st=-1;
        string ans="";
        for(auto x:t) ma[x]++;
        for(int i=0,j=0;i<s.size();i++){
            mp[s[i]]++;
            while(j<=i and ch()){
                if(ml>i-j+1){
                    ml=i-j+1;
                    st=j;
                }
                mp[s[j]]--;
                j++;
            }
        }
        if(ml<1e9) return s.substr(st,ml);
        return ans;
    }
};