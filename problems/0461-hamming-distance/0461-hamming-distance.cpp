class Solution {
public:
    int hammingDistance(int x, int y) {
        int k=0;
        while(max(x,y)>0){
            if((x&1)^(y&1)) k++;
            x=x>>1,y=y>>1;
            // cout<<
        }
        return k;
    }
};