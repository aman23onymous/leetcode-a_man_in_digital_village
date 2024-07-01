class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> x;
        x.push_back(1);
        x.push_back(1);
        int a=1,b=1,y=0;
        while(a+b<=k){
            x.push_back(a+b);
            a=x[x.size()-1];
            b=x[x.size()-2];
        }
        for(int i=x.size()-1;k>0&&i>=0;i--){
            if(k-x[i]>=0){
                k-=x[i],y++;
                cout<<x[i]<<endl;
            }
        }
        return y;
    }
};