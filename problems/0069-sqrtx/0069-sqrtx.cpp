class Solution {
public:
    int mySqrt(int x) {
        // if(x==0) return 0;
        // int r=0; 
        // while(1){r++;
        //     if(r>=46340) return 46340;
        //     if(x>=r*r&&x<(r+1)*(r+1)) break;
        // }
        // return r;
        int hi=x,lo=0;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            long long m = (long long)mid;
            long long y = (long long)x;
            if(m*m==y) return mid;
            else if(m*m>y) hi=mid-1;
            else lo=mid+1;
        }
        return hi;
    }
};