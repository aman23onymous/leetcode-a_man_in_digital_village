class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int z=money,a=prices.size(),b=2;
        for(int i=0;i<a&&b>0;i++){
            if(prices[i]<=z){
                z-=prices[i];
                b--;
            }
        }
        if(b>0) return money;
        return z;
    }
};