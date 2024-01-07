class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int r=0,p=x;
        for(;x!=0;x/=10){
            if(r>214748364.7) return false;
            r=r*10+(x%10);
        }
        if(p==r) return true;
        return false;
    }
};