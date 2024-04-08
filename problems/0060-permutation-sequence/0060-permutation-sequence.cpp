class Solution {
public:
    string helper(string str,int k,string ans){
        if(str.size()==1){
            ans+=str;
            return ans;
        }
        int fact=1;
        for(int i=1;i<str.size();i++){
            fact*=i;
        }
        int idx=k/fact,k2=k%fact;
        if(k%fact==0) idx--,k2+=fact;
        string left=str.substr(0,idx),right=str.substr(idx+1);
        return helper(left+right,k2,ans+str[idx]);
    }
    string getPermutation(int n, int x) {
        string a="",b="";
        for(int i=1;i<=n;i++){
            a+=to_string(i);
        }
        return helper(a,x,b);
    }
};