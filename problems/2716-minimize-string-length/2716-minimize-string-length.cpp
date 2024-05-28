class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> a(26,0);
        for(int i=0;i<s.size();i++){
            a[s[i]-97]++;
        }
        int k=0;
        for(int i=0;i<26;i++){
            if(a[i]>0) k++;
        }
        return k;
    }
};