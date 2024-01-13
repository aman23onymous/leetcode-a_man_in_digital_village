class Solution {
public:
    bool isThree(int n) {
        int i,k=0;
        for(i=1;i<=n;i++){
            if(n%i==0){
                k++;
            }
        }
        if(k==3) return true;
        return false;
    }
};