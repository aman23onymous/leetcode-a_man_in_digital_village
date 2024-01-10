class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)  return 1;
        int i=2;
        while(i<=num/2){
            if(i>46340) return false;
            if(num==(i*i)) return true;
            i++;
        }
        return false;
    }
};