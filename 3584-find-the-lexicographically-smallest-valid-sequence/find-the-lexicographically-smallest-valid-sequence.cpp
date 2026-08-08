class Solution {
public:
    vector<int> validSequence(std::string s, std::string t) {
        int n=s.size(),m=t.size();
        vector<int> a(m,-1);
        for(int i=n-1,j=m-1;i>=0 and j>=0;i--){
            if(s[i]==t[j]){
                a[j]=i;
                j--;
            }
        }
        bool ch=1;
        vector<int> ans;
        for(int i=0,j=0;i<n and j<m;i++){
            if(s[i]==t[j]){
                ans.push_back(i);
                j++;
            }
            else if(ch and( j==m-1 or a[j+1]>i)){
                ch=0;
                ans.push_back(i);
                j++;
            }
        }
        if(ans.size()==m) return ans;
        return {};
    }
};
