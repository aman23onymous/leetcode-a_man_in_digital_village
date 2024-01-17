class Solution {
public:
    
    vector<int> getRow(int rowIndex) {
        long i=(long)rowIndex;
        long curr=1;
        vector<int> p;
        for(long j=0;j<=i;j++){
            p.push_back((int)curr);
            curr=curr*(i-j)/(j+1);
        }
        return p;
    }
};