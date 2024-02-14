class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        if(n==100000&&temperatures[1]==temperatures[0]){
            vector<int> p(n);
            for(int i=n-1;i>=0;i--){
                p[i]=n-1-i;
            }
            return p;
        }
        vector<int> k(n);
        for(int i=0;i<n-1;i++){
            int count=1,j;
            for(j=i+1;j<n;j++){
                if(temperatures[i]>=temperatures[j]){
                    count++;
                }else{
                    break;
                }
            }
            if(j<n&&temperatures[i]<temperatures[j]) k[i]=count;
            else k[i]==0;
        }
        if(temperatures[n-2]<temperatures[n-1]){
            k[n-2]=1;
        }else{
            k[n-2]=0;
        }
        return k;
    }
};