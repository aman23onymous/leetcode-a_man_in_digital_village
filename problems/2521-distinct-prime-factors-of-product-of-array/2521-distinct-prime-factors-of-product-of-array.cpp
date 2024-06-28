class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int m=0;
        for(int i=0;i<nums.size();i++) m=max(m,nums[i]);
        vector<bool> x(m+1,1);
        x[0]=0,x[1]=0;
        for(int i=2;i<=sqrt(m);i++){
            if(x[i]) for(int j=2*i;j<=m;j+=i) x[j]=0;
        }
        // int k=0;
        vector<int> k;
        for(int i=2;i<=m;i++) if(x[i]) k.push_back(i);
        vector<bool> p(k.size(),0);
        // cout<<k[0]<<k[k.size()-1];
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<k.size();j++){
                if(nums[i]<k[j]) break;
                if(nums[i]%k[j]==0) p[j]=1;
                // if(nums[i]%k[j]==0)cout<<k[j];
            }
        }
                // cout<<p[1];

        int c=0;
        for(int i=0;i<p.size();i++) if(p[i]) c++;
        return c;
    }
};