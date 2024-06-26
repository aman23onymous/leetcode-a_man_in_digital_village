class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=100000,x=0;
        for(int i=0;i<prices.size();i++){
            if(mn>prices[i]){
                mn=prices[i];
                cout<<i;
            }
            else{
                x=max(x,prices[i]-mn);
                cout<<i;
            }
        }
       
        return x;
    }
};