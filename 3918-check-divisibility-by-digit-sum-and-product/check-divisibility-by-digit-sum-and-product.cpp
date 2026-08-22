class Solution {
public:
    bool checkDivisibility(int n) {
        int x=0,y=1,z=n;
        while(n){
            x+=(n%10);
            y*=(n%10);
            n/=10;
        }
        return z%(x+y)==0;
    }
};