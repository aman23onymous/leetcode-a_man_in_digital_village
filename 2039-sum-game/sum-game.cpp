class Solution {
public:
    bool sumGame(string s) {
        int a=0,b=0,c=0,d=0;
        for(int i=0;i<s.size()/2;i++){
            if(s[i]=='?') a++;
            else b+=(s[i]-'0');
        }
        for(int i=s.size()/2;i<s.size();i++){
            if(s[i]=='?') c++;
            else d+=(s[i]-'0');
        }

        if(a==c and b==d) return 0;
        if((a>c and b>d) or (a<c and b<d)) return 1;
        cout<<"hi";
        if(abs(b-d)%9 or abs(a-c)%2) return 1;
        return abs(a-c)/2!=abs(b-d)/9;
    }
};