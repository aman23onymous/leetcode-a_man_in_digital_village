class Solution {
public:

        bool w(int n){

    if(n==1) return 0;
    for(int i=2;i<=sqrt(n);i++) if(n%i==0) return 0;
    return 1;
}

int smallestValue(int n){
    if(n==4)return  4;
    while(!(w(n))){
        int x=0,b=n;
        for(int i=1;i<sqrt(n);i++) if(n%i==0&&w(i)) while(b%i==0) b/=i,x+=i;
        b=n;

        for(int i=sqrt(n);i>0;i--) if(n%i==0&&w(n/i)) while(b%(n/i)==0) b/=(n/i),x+=(n/i);
        n=x;
    }
    
    return n;
}

};