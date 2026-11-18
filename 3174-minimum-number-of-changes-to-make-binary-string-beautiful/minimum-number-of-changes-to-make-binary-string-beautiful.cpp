class Solution {
public:
    int minChanges(string s) {
        vector<int> l;
        for(int i=0;i<s.size();i++){
            int j=i;
            while(j<s.size() and s[j]==s[i]) j++;
            l.push_back(j-i);
            i=j-1;
        }
        bool od=0;
        int ans=0;
        for(int i=0;i<l.size();i++){
            if(l[i]%2){
                int j=i+1;
                while(l[j]%2==0) j++;
                ans+=(j-i);
                i=j;
            }
        }
        return ans;
    }
};