class Solution {
public:
    int tribonacci(int n){
        int F[38];
        F[0]=0;
        F[1]=1;
        F[2]=1;
        for(int i=0;i<35;i++){
            F[i+3]=F[i+2]+F[i+1]+F[i];
        }
        return F[n];
    }
};