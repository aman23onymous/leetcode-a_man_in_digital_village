class Solution {
public:
    string reverseWords(string s) {
        string r="";
        int n=s.size(),i=s.size()-1,j=s.size()-1;
        while(s[i]==' ') i--,j--;
        while(i>=0&&j>=0){
            if(s[j]==' '){
                r+=s.substr(j+1,i-j);
                r+=" ";
                // cout<<i<<" "<<j<<endl;
                while(j>=0&&s[j]==' ') j--;
                i=j;
            }
            else j--;
        }
        if((i==-1||j==-1)&&r==""){
            i=n-1;
            while(s[i]==' ') i--;
            return s.substr(0,i+1);
        }
        // r+=" ";
        j=0;
        cout<<"hi";
        while(s[j]==' ') j+=1;
        // cout<<hi;
        r+=s.substr(j,i+1);
        r=r.substr(1,r.size()-1);
        i=n-1;
        while(s[i]==' ') i--;
        while(s[i]!=' ') i--;
        while(r[r.size()-1]==' ') r.pop_back();
        r=s.substr(i+1,1)+r;
        return r;
    }
};