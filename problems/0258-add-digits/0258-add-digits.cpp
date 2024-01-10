class Solution {
public:
   int addDigits(int num) {
        int k=num,nw;
        while(num>=10){
            nw=0;
            while(k>0){
                nw=nw+(k%10);
                k=k/10;
            }
            k=nw;
            num=nw;
        }
        return num;
    }
};