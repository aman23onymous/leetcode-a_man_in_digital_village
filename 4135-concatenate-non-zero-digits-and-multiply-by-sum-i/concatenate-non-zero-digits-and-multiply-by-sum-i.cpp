class Solution {
public:
    long long sumAndMultiply(int n) {
        string st=to_string(n);
        long long s=0,x=0;
        for(auto y:st){
            s+=(y-'0');
            if(y-'0') x=x*10+y-'0';
        }
        return s*x;
    }
};