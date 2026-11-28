class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]<s[i+1]){
                int j=s.size()-1;
                while(s[j]<=s[i]) j--;
                swap(s[i],s[j]);
                reverse(begin(s)+i+1,end(s));
                string t=to_string(INT_MAX);
                if(s.size()>t.size() or (s.size()==t.size() and s>t)) return -1;
                return stoi(s);
            }
        }
        return -1;
    }
};