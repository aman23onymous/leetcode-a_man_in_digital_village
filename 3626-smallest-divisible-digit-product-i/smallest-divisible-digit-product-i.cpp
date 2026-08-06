class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;;i++){
            int j=i,u=1;
            while(j) u*=(j%10),j/=10;
            if(u%t==0) return i;
        }
        return n;
    }
};