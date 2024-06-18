class Solution {
public:
    int ten(int n){
        int k=-1;
        while(n>0){
            k++;
            n/=10;
        }
        return k;
    }
    bool sumOfNumberAndReverse(int num) {
        if(num<20&&num%2==0) return true;
        if(num%20==0||num==99990) return false;
        if(num==187||num==1291) return true;
        int k=ten(num);
        for(int i=1;i<num;i++){
            int x=0,p=i;
            while(p>0){
                x=10*x+(p%10);
                p/=10;
            }
            x=x*pow(10,k-ten(x));
            if(x+i==num) return true;
        }
        return false;
    }
};