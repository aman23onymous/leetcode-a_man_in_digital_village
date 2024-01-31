class Solution {
public:
bool issq(int x){
int n = sqrt(x);
if(n*n==x) return true;
return false;
}
    bool judgeSquareSum(int c) {
        int hi=c,lo=0,mid;
        while(hi>=lo){
            if(issq(hi)&&issq(lo)){
                cout<<hi<<" "<<lo;
                return true;
            }
            else if(!issq(lo)){
                hi=(int)sqrt(hi)*(int)sqrt(hi);
                lo=c-hi;
            }
            else{
                lo=(int)(sqrt(lo)+1)*(int)(sqrt(lo)+1);
                hi=c-lo;
            }
        }
        
        return false;
    }
};