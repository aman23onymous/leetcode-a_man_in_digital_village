class Solution {
public:
    int arrangeCoins(int n) {
        if(n<2) return n;
        long long sum=0;
        int i;
        for(i=1;i<n;i++){
            sum=sum+i;
            if(sum>n) break;
        }
        return i-1;
    }
};