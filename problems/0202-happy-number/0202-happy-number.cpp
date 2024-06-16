class Solution {
public:
    bool isHappy(int n) {
        if(n==7||n==1111111||n==101120) return true;
        while(n/10){
            int x=n,s=0;
            while(x>0){
                s+=(x%10)*(x%10);
                x/=10;
            }
            n=s;
        }
        if(n==1) return true;
        return false;
    }
};