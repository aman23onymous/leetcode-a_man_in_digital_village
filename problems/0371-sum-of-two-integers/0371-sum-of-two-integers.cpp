class Solution {
public:
    int getSum(int a, int b) {
        int sum=a^b;
        int carry=a&b;
        carry<<=1;
        while (carry!=0){
            int tempsum=sum;
            sum=sum^carry;
            carry=tempsum&carry;
            carry<<=1;
        }
        
        return sum;
    }
};