class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        for(auto x:num){
            while(k and s.size() and s.back()>x){
                k--;
                s.pop_back();
            }
            s.push_back(x);
        }
        while(k-- and s.size()){
            s.pop_back();
        }
        int i=0;
        while(s[i]=='0'){
            i++;
        }
        s=s.substr(i);
        if(s=="") return "0";
        return s;
    }
};