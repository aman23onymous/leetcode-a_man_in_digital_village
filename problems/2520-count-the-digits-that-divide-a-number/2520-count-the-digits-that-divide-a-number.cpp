class Solution {
public:
    int countDigits(int num) {
        int n=num,k=0;
        while(n>0){
            if(num%(n%10)==0) k++;
            n/=10;
        }
        return k;
    }
};