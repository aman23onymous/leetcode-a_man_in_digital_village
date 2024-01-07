class Solution {
public:
    int trailingZeroes(int n) {
        int zero=0,j=0;
        while(n>pow(5,j)){
            j++;
        }
        for(int i=1;i<=j;i++){
            zero=zero+n/pow(5,i);
        }
        return zero;
    }
};