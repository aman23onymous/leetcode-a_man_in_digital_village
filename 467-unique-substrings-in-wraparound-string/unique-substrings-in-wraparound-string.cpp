class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> a(26,0);
        for(int i=0;i<s.size();i++){
            int j=i+1;
            while(j<s.size() and ((s[j]-s[j-1]+26)%26)==1) j++;
            a[s[i]-'a']=max(a[s[i]-'a'],j-i);
            i=j-1;
        }
        for(int i=0;i<26;i++){
            int j=a[i]-1,k=(i+1)%26;
            while(k!=i and a[k]<j and j>0){
                a[k]=j;
                k=(k+1)%26;
                j--;
            }
        }
        // cout<<"\n";
        // for(auto x:a) cout<<x<<" ";
        return accumulate(begin(a),end(a),0);
    }
};