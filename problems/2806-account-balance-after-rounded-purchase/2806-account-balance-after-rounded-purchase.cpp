class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if(purchaseAmount==0) return 100;
        if(purchaseAmount==100) return 0;
        int i;
        for(i=0;i<100;i+=10){
            if(purchaseAmount>i&&purchaseAmount<=i+10) break; 
        }
        cout<<i;
        if((purchaseAmount-i)>=(i+10-purchaseAmount)) return 90-i;
        return 100-i;
    }
};