class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26,0),b(26,0);
        for(int i=0;i<s.size();i++) a[s[i]-97]++;
        for(int i=0;i<t.size();i++) b[t[i]-97]++;
        int k=0;
        for(int i=0;i<26;i++) k+=abs(a[i]-b[i]);
        return k/2;
    }
};