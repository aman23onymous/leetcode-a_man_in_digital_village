class Solution {
public:
    int reti(vector<int>& a,int i,int j){
        int s=0;
        for(int k=i;k<=j;k++){
            int l=k+1;
            while(l<=j and a[l]!=a[k]) l++;
            if(k!=l-1)s+=(2*reti(a,k+1,l-1));
            else s+=1;
            k=l;
        }
        return s;
    }
    int scoreOfParentheses(string s) {
        int n=s.size();
        vector<int> a(n);
        int k=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') a[i]=++k;
            else a[i]=k--;
        }
        return reti(a,0,n-1);
    }
};