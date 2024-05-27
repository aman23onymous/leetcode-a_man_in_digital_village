class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0,y=x;
        while(y>0){
            sum+=(y%10);
            y/=10;
        }
        cout<<sum;
        if(x%sum==0) return sum;
        return -1;
    }
};