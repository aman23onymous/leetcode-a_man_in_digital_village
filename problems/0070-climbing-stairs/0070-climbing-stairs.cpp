class Solution {
public:
    int climbStairs(int n) {
        int C[45];//ACTUALLY THIS ARRAY REPRESENT NO. OF WAYS,IT'S Ith INDEX REPRESENT NO.OF WAYS TO CLIMB I+1 STEPS
        C[0]=1;///THIS REPRESENT WHEN ONE STAIR IS LEFT
        C[1]=2;///THIS REPRESENT WHEN ONE STAIR IS LEFT
        for(int i=0;i<43;i++){
            C[i+2]=C[i+1]+C[i];
        }
        return C[n-1];

    }
};