class Solution {
public:
    long long fc[100001],mod=1000000007;
    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    void fact(){
        fc[0]=1;
        for(int i=1;i<100001;i++){
            fc[i]=(fc[i-1]*i)%mod;
        }
    }
    long long inv(long long x){
        return power(x,mod-2)%mod;
    }
    long long nCr(long long n,long long r){
        if(n<=r)return 1;
        return fc[n]*inv(fc[r]) % mod * inv(fc[n-r]) % mod;
    }
    int numberOfSequence(int n, vector<int>& sick) {
        fact();
        long long t=n-sick.size();
        long long res=nCr(t,sick[0]);
        t-=sick[0];
        for(int i=0;i<sick.size()-1;i++){
            long long as=sick[i+1]-sick[i]-1;
            if(as==0) continue;
            res=(res*nCr(t,as))%mod;
            t-=as;
            res=(res*power(2,as-1))%mod;
        }
        return res;
    }
};