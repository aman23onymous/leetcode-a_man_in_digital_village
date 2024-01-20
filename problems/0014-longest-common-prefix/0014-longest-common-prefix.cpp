class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        sort(strs.begin(),strs.end());
        string first=strs[0],k="";
        string last=strs[strs.size()-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]==last[i]) k+=first[i];
            else break;
        }
        return k;
    }
};