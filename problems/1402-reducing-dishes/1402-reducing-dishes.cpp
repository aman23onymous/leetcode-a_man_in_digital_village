class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int n=sat.size();
        vector<int> suf(n);
        suf[n-1]=sat[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=sat[i]+suf[i+1];
        }
        int s=0;
        for(int i=0;i<n;i++){
            if(suf[i]>0) s+=suf[i];
        }
        return s;
    }
};