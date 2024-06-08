class Solution {
public:
    bool checkString(string s) {
        int a=-1,b=s.size();
        for(int i=s.size();i>=0;i--){
            if(s[i]=='a'){
                a=i;
                break;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                b=i;
                break;
            }
        }
        return (a<b);
    }
};