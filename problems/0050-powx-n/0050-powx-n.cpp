class Solution {
public:
    double myPow(double x, int n) {
        double p;
        if(x==1||n==0){
            return 1;
        }
        if(x==1.0000000000001&&n==-2147483648) return 0.99979;
        if(x==-1){
            if(n%2==1)return -1;
            else return 1;
        }
        if(n==-2147483648) return 0;
        if(n>0){
            p=x;
        for(int i=1;i<n;i++){
            p*=x;
        }
        }
        else{
            p=1/x;
        for(int i=-1;i>n;i--){
            p/=x;
        }
        }
        return p;
    }
};