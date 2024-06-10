class Solution {
public:
    int numberOfChild(int n, int k) {
        int x=k%(n-1);
        int y=k/(n-1);
        // if(x==0){
        //     if(y%2==1) return n-1;
        //     else return 0;
        // }
        if(y%2==1) return n-1-x;
        return x;
    }
};